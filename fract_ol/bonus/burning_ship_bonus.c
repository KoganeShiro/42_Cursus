/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:24:14 by cejin             #+#    #+#             */
/*   Updated: 2023/12/22 14:42:26 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	burning_ship_cx(int x, t_fractal *fractal)
{
	t_fractal	c;

	c.x = (map_scaling((t_scaling_value){.unscaled_num = x,
				.new_min = -2, .new_max = 2, .old_min = 0,
				.old_max = WIDTH}) * fractal->zoom) + fractal->shift_x;
	return (c.x);
}

double	burning_ship_cy(int y, t_fractal *fractal)
{
	t_fractal	c;

	c.y = (map_scaling((t_scaling_value){.unscaled_num = y,
				.new_min = 2, .new_max = -2, .old_min = 0,
				.old_max = HEIGHT}) * fractal->zoom) + fractal->shift_y;
	return (c.y);
}

//like mandelbrot but z = abs(z)^2+c
void	render_burning_ship(int x, int y, t_fractal *fractal)
{
	t_fractal	z;
	t_fractal	c;
	double		tmp;
	int			iter;
	int			color;

	iter = -1;
	z.x = 0.0;
	z.y = 0.0;
	c.x = burning_ship_cx(x, fractal);
	c.y = burning_ship_cy(y, fractal);
	c.y = -c.y;
	while (++iter < fractal->iteration_nb)
	{
		tmp = (z.x * z.x) - (z.y * z.y);
		z.y = 2 * fabs(z.x * z.y) + c.y;
		z.x = tmp + c.x;
		if (fabs((z.y * z.y) + (z.x * z.x)) > fractal->escape_value)
		{
			color = map_colo(iter, BLACK, WHITE, fractal->iteration_nb);
			ft_put_pixel(x, y, &fractal->image, color);
			return ;
		}
	}
	ft_put_pixel(x, y, &fractal->image, BLACK);
}
