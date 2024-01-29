/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:15:50 by cejin             #+#    #+#             */
/*   Updated: 2023/12/21 18:09:58 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	mandelbrot_cx(int x, t_fractal *fractal)
{
	t_fractal	c;

	c.x = (map_scaling((t_scaling_value){.unscaled_num = x,
				.new_min = -2, .new_max = 2, .old_min = 0,
				.old_max = WIDTH}) * fractal->zoom) + fractal->shift_x;
	return (c.x);
}

double	mandelbrot_cy(int y, t_fractal *fractal)
{
	t_fractal	c;

	c.y = (map_scaling((t_scaling_value){.unscaled_num = y,
				.new_min = 2, .new_max = -2, .old_min = 0,
				.old_max = HEIGHT}) * fractal->zoom) + fractal->shift_y;
	return (c.y);
}
/*
zn+1 = zn^2 + c where z = x + yi and i^2 = -1
z = 0 and c = point of interest (the pixel)
diverging, has no limit or its infinite
converging, has a limit
*/

void	render_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_fractal	z;
	t_fractal	c;
	double		tmp;
	int			iter;
	int			color;

	iter = -1;
	z.x = 0.0;
	z.y = 0.0;
	c.x = mandelbrot_cx(x, fractal);
	c.y = mandelbrot_cy(y, fractal);
	while (++iter < fractal->iteration_nb)
	{
		tmp = (z.x * z.x) - (z.y * z.y);
		z.y = (2 * z.x * z.y) + (c.y);
		z.x = tmp + c.x;
		if (((z.y * z.y) + (z.x * z.x)) > fractal->escape_value)
		{
			color = map_colo(iter, BLACK, WHITE, fractal->iteration_nb);
			ft_put_pixel(x, y, &fractal->image, color);
			return ;
		}
	}
	ft_put_pixel(x, y, &fractal->image, BLACK);
}
/*
void	render_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_fractal	z;
	t_fractal	c;
	double		tmp;
	int			iter;
	int			color;

	iter = -1;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (map_scaling((t_scaling_value){.unscaled_num = x,
				.new_min = -2, .new_max = 2, .old_min = 0,
				.old_max = WIDTH}) * fractal->zoom) + fractal->shift_x;
	c.y = (map_scaling((t_scaling_value){.unscaled_num = y,
				.new_min = 2, .new_max = -2, .old_min = 0,
				.old_max = HEIGHT}) * fractal->zoom) + fractal->shift_y;
	while (++iter < fractal->iteration_nb)
	{
		tmp = (z.x * z.x) - (z.y * z.y);
		z.y = (2 * z.x * z.y) + (c.y);
		z.x = tmp + c.x;
		if (((z.y * z.y) + (z.x * z.x)) > fractal->escape_value)
		{
			color = map_colo(iter, BLACK, WHITE, 1);
			ft_put_pixel(x, y, &fractal->image, color);
			return ;
		}
	}
	ft_put_pixel(x, y, &fractal->image, BLACK);
}
*/
