/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:36:11 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:36:44 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minirt.h"

float	shoot_ray(t_graphics *rt, t_vec3 *x_ray, t_vec3 *y_ray)
{
	t_vec3		ray_without_z;
	t_point3	z;
	t_vec3		view_origin_point;
	float		color;

	rt->nearest_obj->obj = rt->lst_obj;
	vec3_add_to(&ray_without_z,
		x_ray, y_ray);
	vec3_mult_by_val_to(&z,
		&rt->camera->direction, rt->viewport->dist_view_cam);
	vec3_add_to(&view_origin_point,
		&ray_without_z, &z);
	rt->ray->origin = rt->camera->pos;
	rt->ray->direct = view_origin_point;
	normalized(&rt->ray->direct);
	color = get_nearest_obj(rt);
	return (color);
}

void	loop_through_all_the_pixels(t_graphics *rt)
{
	int		color;
	t_vec3	x_ray;
	t_vec3	y_ray;

	rt->canva_y = 0;
	x_ray = (t_vec3){0};
	y_ray = (t_vec3){0};
	while (rt->canva_y < rt->viewport->vh)
	{
		rt->canva_x = 0;
		scale_viewport_to_canva(rt, &x_ray, &y_ray, 'y');
		while (rt->canva_x < rt->viewport->vw)
		{
			scale_viewport_to_canva(rt, &x_ray, &y_ray, 'x');
			color = shoot_ray(rt, &x_ray, &y_ray);
			my_pixel_put(rt, color);
			rt->canva_x++;
		}
		rt->canva_y++;
	}
}

void	my_pixel_put(t_graphics *rt, int color)
{
	char	*index;

	index = rt->mlx->addr
		+ (rt->canva_y * rt->mlx->line_len
			+ rt->canva_x * (rt->mlx->img_bpp / 8));
	*(unsigned int *)index = color;
}

void	render_image(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_init,
		mlx->mlx_window, mlx->image_ptr, 0, 0);
}

void	raytracing(t_graphics *rt)
{
	create_viewport(rt);
	loop_through_all_the_pixels(rt);
	render_image(rt->mlx);
}
