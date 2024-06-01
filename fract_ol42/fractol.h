/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:10:05 by cejin             #+#    #+#             */
/*   Updated: 2023/12/20 18:33:09 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <math.h>
# include "minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

/* invalid arg */
# define ERROR_MESSAGE "\nInvalid argument\n \
Please enter\n\n\tmandelbrot\nor \
						\n\tjulia <value_1> <value_2>"

/* window size */
# define WIDTH	900
# define HEIGHT	900

/* COLORS */
# define BLACK				0x000000  // RGB(0, 0, 0)
# define WHITE				0xFFFFFF  // RGB(255, 255, 255)
# define RED				0xFF0000  // RGB(255, 0, 0)
# define GREEN				0x00FF00  // RGB(0, 255, 0)
# define BLUE				0x0000FF  // RGB(0, 0, 255)
# define MAGENTA_BURST		0xFF00FF  // RGB(255, 0, 255) | A vibrant magenta
# define LIME_SHOCK			0xCCFF00  // RGB(204, 255, 0) | A blinding lime
# define NEON_ORANGE		0xFF6600  // RGB(255, 102, 0) A blazing neon orange
# define PSYCHEDELIC_PURPLE	0x660066  // RGB(102, 0, 102) | A deep purple
# define AQUA_DREAM			0x33CCCC  // RGB(51, 204, 204) | A bright turquoise
# define HOT_PINK			0xFF66B2  // RGB(255, 102, 178) | A pink pink
# define ELECTRIC_BLUE		0x0066FF  // RGB(0, 102, 255) | A radiant blue
# define LAVA_RED			0xFF3300  // RGB(255, 51, 0) | A bright, molten red

/* STRUCT */
typedef struct s_scaling_value
{
	double	unscaled_num;
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
}			t_scaling_value;

typedef struct s_img
{
	void	*image_ptr; //-> to image struct 
	char	*pixels_ptr; //-> to the actual pixel (pixel that will change)
	int		bits_per_pixel;
	int		endian; //is the pc little endian or big endian
	int		line_len; //data alignement
}			t_img;

typedef struct s_fractal
{
	char	*name;
	//minilibx
	void	*mlx_connection; // mlx_init()
	void	*mlx_window; //mlx_new_window()
	//image
	t_img	image;
	double	x;
	double	y;
	//hook
	double	escape_value;
	int		iteration_nb;
	double	shift_x;
	double	shift_y;
	double	zoom;
}			t_fractal;

/*MAIN*/
void	data_value(t_fractal *fractal);
int		main(int argc, char **argv);

/*WINDOWS*/
void	ft_check_errors(t_fractal *fractal);
int		fractol_init(t_fractal *fractal);
int		handle_close(t_fractal *fractal);

/*RENDERING*/
void	render_fractol(t_fractal *fractal);

/*IMAGE*/
void	ft_put_pixel(int x, int y, t_img *image, int color);
double	map_scaling(t_scaling_value num);
double	map_colo(double unscaled_num, double new_min,
			double new_max, double old_max);

/*MOVE AND ZOOM*/
void	hook_event(t_fractal *fractal);
int		keyboard_event(int key, t_fractal *fractal);
int		keyboard_event2(int key, t_fractal *fractal);
int		handle_mouse_zoom(int button, int x, int y, t_fractal *fractal);

/*MANDELBROT*/
void	render_mandelbrot(int x, int y, t_fractal *fractal);

/*JULIA SET*/
void	render_julia(int x, int y, t_fractal *fractal);

/*UTILS*/
int		ft_strcmp(char *s1, char *s2);
double	ft_atodbl(char *av_value);

/*PRINTF*/
int		printf_format(va_list args, const char format);
int		ft_printf(const char *format, ...);
void	ft_putchar(const char c);
int		ft_printchar(const char c);
int		ft_printstr(const char *str);
int		ft_printnbr(int n);
int		ft_printunsigned(unsigned int n);
int		ft_printhex(unsigned long nb, char *hex);
int		ft_printptr(unsigned long long ptr);

#endif
