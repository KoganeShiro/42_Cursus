/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:10:50 by cejin             #+#    #+#             */
/*   Updated: 2024/11/13 18:40:00 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./../libft/libft.h"
# include "mlx.h"

# include <stdarg.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>

# define WINDOW_NAME		"MiniRT"

# define NOT_THE_OBJ		-42
# define OBJ_DOUBLE			-INFINITY

# define ERR_MISS_OBJ		"ERROR: Need ONE Camera, Ambient and Light !"
# define ERR_TOO_MANY_ARG	"ERROR: Too many argument, \
each arg need to be separate by a space on"
# define ERR_WRONG_NB_ARG	"arguments, each arg need \
to be separate by a space"
# define UNKNOWN_OBJ		"ERROR: Unknown object in the file"
# define WRONG_RGB_RANGE	"ERROR: R,G and B should be between [0;255]"
# define VEC_NOT_NORMALIZED	"ERROR: vect is not normalize ([-1;1])"
# define POS_FORMAT			"pos should be in this format [x,y,z]"
# define RGB_FORMAT			"RGB should be in this format [r,g,b]"
# define VEC_FORMAT			"vec should be in this format [x,y,z]"

# define WIDTH				1000
# define HEIGHT				1000
# define DELTA				0.01

typedef enum e_objects
{
	CAMERA,
	AMBIENT,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
}	t_objects_type;

typedef enum e_side
{
	INSIDE,
	OUTSIDE
}	t_side;

typedef struct s_mlx
{
	char	*addr;
	void	*mlx_init; // mlx_init()
	void	*mlx_window; //mlx_new_window()
	void	*image_ptr; //-> to image struct 
	char	*pixels_ptr; //-> to the actual pixel (pixel that will change)
	int		img_bpp;
	int		endian; //is the pc; little endian or big endian
	int		line_len; //data alignement
}	t_mlx;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef t_vec3	t_point3;

typedef struct s_sphere
{
	t_vec3		pos;
	t_color		color;
	t_vec3		color_vec;
	float		diameter;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	pos;
	t_vec3	direc;
	t_color	color;
	t_vec3	color_vec;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	pos;
	float	diameter;
	float	height;
	t_color	color;
	t_vec3	color_vec;
	t_vec3	axis_vec;
}	t_cylinder;

typedef struct s_geo_obj
{
	t_objects_type		type;
	t_sphere			*sphere;
	t_cylinder			*cylinder;
	t_plane				*plane;
	struct s_geo_obj	*next;
}	t_geo_obj;

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direct;
}	t_ray;

typedef struct s_camera
{
	t_point3	pos; //also origin
	t_vec3		direction;
	float		fov;
}	t_camera;

typedef struct s_ambient
{
	t_point3	pos;
	float		lightness_ratio;
	t_color		color;
	t_vec3		color_vec;
}	t_ambient;

typedef struct s_light
{
	t_point3	pos;
	float		brightness_ratio;
}	t_light;

typedef struct s_hit
{
	bool		no_hit;
	t_geo_obj	*obj;
	float		distance;
	t_ray		go_light_ray;
	t_vec3		impact_point;
	bool		got_light;
	t_side		side; //doesn't seems to work
}	t_hit;

typedef struct s_viewport
{
	float	vh;
	float	vw;
	t_vec3	view_x;
	t_vec3	view_y;
	float	dist_view_cam;
}	t_viewport;

typedef struct s_graphics
{
	t_mlx		*mlx;
	t_camera	*camera;
	t_ambient	*ambient;
	t_light		*light;
	t_geo_obj	*lst_obj;
	t_hit		*nearest_obj;
	t_viewport	*viewport;
	t_ray		*ray;
	int			canva_x;
	int			canva_y;
	int			has_require_obj;
}	t_graphics;

/*
		// MAIN //
*/
int			main(int argc, char **argv);

/*
		// INIT //
*/
int			create_linked_list(t_graphics *rt);
int			init_data(t_graphics *rt, t_mlx *mlx, char *file);

/*
		// MLX //
*/
int			cross_escape(t_mlx *mlx);
int			key_escape(int key, t_graphics *rt);
int			init_mlx(t_graphics *graphics, t_mlx *mlx);
void		run_mlx(t_mlx *mlx, t_graphics *rt);
void		destroy_mlx(t_mlx *mlx);

/*
		// PARSING //
*/
//int	test(const char *file, t_graphics *rt); //
int			parse_file(const char *file, t_graphics *rt);

/*
		// SET FUNCTIONS  IN PARSING/ //
*/
int			is_right_pos(char **pos);
int			set_position(t_graphics *rt, t_objects_type obj, char *split);

int			set_normalized_pl_vect(t_plane *pl, char *split);
int			set_normalized_cy_vect(t_cylinder *cy, char *split);
int			set_normalized_cam_vect(t_camera *cam, char *split);

int			set_sp_rgb(t_sphere *sp, char *split);
int			set_pl_rgb(t_plane *pl, char *split);
int			set_cy_rgb(t_cylinder *cy, char *split);
int			set_amb_rgb(t_ambient *amb, char *split);

/*
		// PARSING/FUNCTION_CHECK //
*/
bool		normalized_check(t_vec3 vec);
bool		in_range(t_color color);
bool		light_ratio_check(t_graphics *rt, t_objects_type obj);

/*
		// PARSING/FILL_STRUCT //
*/
int			fill_struct(char *line, int i, t_graphics *rt);

/*
		// PARSING/FILL_CHECK_CAMERA //
*/
int			fill_camera(char *line, t_graphics *rt);

/*
		// PARSING/FILL_CHECK_GLB_LIGHTS //
*/
int			fill_light(char *line, t_graphics *rt);
int			fill_ambient(char *line, t_graphics *rt);

/*
		// PARSING/LINKED_LIST //
*/
t_geo_obj	*add_end_node(t_graphics *rt,
				t_geo_obj **head, t_objects_type type);
t_geo_obj	*create_new_node(t_objects_type type);

/*
		// FILL_CHECK GEO OBJ //
*/
int			fill_sphere(char *line, t_geo_obj *sp);
int			fill_plane(char *line, t_geo_obj *pl);
int			fill_cylinder(char *line, t_geo_obj *cy);

/*
		// RAYTRACING //
*/
float		shoot_ray(t_graphics *rt, t_vec3 *x_ray, t_vec3 *y_ray);
void		loop_through_all_the_pixels(t_graphics *rt);
void		render_image(t_mlx *mlx);
void		my_pixel_put(t_graphics *rt, int color);
void		raytracing(t_graphics *rt);

/*
		// VIEWPORT //
*/
void		create_viewport(t_graphics *rt);

/*
		// GET_NEAREST_OBJ //
*/
float		get_nearest_obj(t_graphics *rt);

/*
		// HIT_ OBJS //
*/
int			hit_sphere(t_graphics *rt, t_hit *sphere, bool light);
int			hit_plane(t_graphics *rt, t_hit *plane, bool light);
int			hit_cylinder(t_graphics *rt, t_hit *cylinder, bool light);

/*
		// HIT //
*/
t_hit		*hit_object(t_graphics *rt, t_geo_obj *object,
				t_hit *hit_what, bool light);

/*
		// GET OBJ COLOR //
*/
int			get_sphere_color(t_graphics *rt, t_hit *nearest);
int			get_plane_color(t_graphics *rt, t_hit *nearest);
int			get_cylinder_color(t_graphics *rt, t_hit *nearest);

/*
		// LIGTH_RAY //
*/
t_vec3		*get_impact_point(t_vec3 *impact_point,
				t_vec3 origin, t_vec3 direct, float distance);
void		send_light_ray(t_graphics *rt, t_hit *nearest);

/*
		// GLB_LIGHT //
*/
t_vec3		ambiant_light_vec(t_graphics *rt);
t_vec3		calculate_glb_light(t_graphics *rt, t_hit *hit,
				t_vec3 light);

/*
		// OBJ LIGHT //
*/
t_vec3		sphere_light(t_graphics *rt, t_hit *hit, t_vec3 color);
t_vec3		plane_light(t_graphics *rt, t_hit *hit, t_vec3 color);
t_vec3		cylinder_light(t_graphics *rt, t_hit *hit, t_vec3 color);

/*
		// GET_COLOR //
*/
int			get_bg_color(t_color color);
int			get_color(t_graphics *rt, t_hit *nearest);
void		init_color_vec(t_graphics *rt);

/*
		// UTILS/COLOR_UTILS //
*/
int			convert_color_struct_to_int(t_color color);
float		color_in_range(t_color color);
t_vec3		*init_vec(t_vec3 *vec, float x, float y, float z);

/*
		// UTILS/MATH_EQUATIONS //
*/
float		discriminant_calcul(float a, float b, float c);
float		*quadratic_equation(float a, float b, float delta);
t_vec3		*cross_product(t_vec3 *dest, t_vec3 *vect1, t_vec3 *vect2);
float		dot_product(t_vec3 *vect1, t_vec3 *vect2);
t_vec3		*normalized(t_vec3 *vec);

/*
			// UTILS/MATH_FUNCTIONS //
*/
float		*get_roots(float a, float b, float c);
float		get_closest_point(float roots[2], t_hit *obj,
				t_vec3 origin, t_vec3 direc);
float		compare_roots(float roots[2], t_hit *obj);

/*
			// UTILS/VEC_OPERATIONS //
*/
t_vec3		*vec3_add_val(t_vec3 *vect, float val);
t_vec3		*vec3_substract_val(t_vec3 *vect, float val);
t_vec3		*inverse_vect(t_vec3 *dest, t_vec3 *src);
float		vect_norme(t_vec3 *vect);
float		dist_between(t_vec3 *vect1, t_vec3 *vect2);

/*
			// UTILS/VEC_FUNCTIONS_TO //
*/
t_vec3		*vec3_add_to(t_vec3 *dest, t_vec3 *vect1, t_vec3 *vect2);
t_vec3		*vec3_sub_to(t_vec3 *dest, t_vec3 *vect1, t_vec3 *vect2);
t_vec3		*vec3_mult_to(t_vec3 *dest, t_vec3 *vect1, t_vec3 *vect2);
t_vec3		*vec3_mult_by_val_to(t_vec3 *dest, t_vec3 *vect1, float val);

/*
			// UTILS/VEC_FUNCTION //
*/
t_vec3		*_get_cy_normal_vec(t_vec3 *normal, t_graphics *rt);
t_vec3		get_normal_vec(t_vec3 *normal, t_graphics *rt,
				t_objects_type type);
t_vec3		*vec3_cpy(t_vec3 *dest, t_vec3 *src);

/*
			// UTILS/UTILS //
*/
bool		has_right_args_nb(char **tab, int args_nb);
bool		is_right_value(char *value, bool plus_flag,
				bool minus_flag, bool dot_flag);
void		scale_viewport_to_canva(t_graphics *rt,
				t_vec3 *x_ray, t_vec3 *y_ray, char coord);
t_vec3		*conv_struct_color_to_vec3(t_vec3 *dest, t_color *color);
t_color		*conv_struc_vec3_to_color(t_color *dest, t_vec3 *vec);

/*
			// UTILS/CLEANUP //
*/
void		free_tab(char **tab);
int			cleanup(t_graphics *rt);

// // FOR TESTS/ DEBUG
// void	print_vec(char *p, t_vec3 *vec);
// void	print_linked_list(t_geo_obj *head);
// void	print_rgb(char *p, t_color *rgb);
// void	print_tab(char **str);
// void	print_point(char *p, t_point3 *vec);
// void	print_obj(t_hit *obj);

// void	print_camera(t_camera *camera);
// void	print_light(t_light *light);
// void	print_ambient(t_ambient *ambient);
// 			// SET_FUNCTION //
// void	set_camera_position(t_camera *camera);
// void	set_normalized_orient_vect(t_camera *camera);
// void	set_fov(t_camera *camera);
// void	set_camera(t_camera *camera);
// void	set_ambient_rgb(t_ambient *ambient);
// void	set_lighting_ratio(t_ambient *ambient);
// void	set_ambient(t_ambient *ambient);
// void	set_light_position(t_light *light);
// void	set_brightness_ratio(t_light *light);
// void	set_light(t_light *light);
// void	set_sphere(t_geo_obj *lst);
// void	set_data(t_graphics *rt);
// //

#endif
