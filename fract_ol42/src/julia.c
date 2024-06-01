/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:15:32 by cejin             #+#    #+#             */
/*   Updated: 2023/12/22 12:18:07 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	julia_zx(int x, t_fractal *fractal)
{
	t_fractal	z;

	z.x = (map_scaling((t_scaling_value){.unscaled_num = x,
				.new_min = -2, .new_max = 2, .old_min = 0,
				.old_max = WIDTH}) * fractal->zoom) + fractal->shift_x;
	return (z.x);
}

double	julia_zy(int y, t_fractal *fractal)
{
	t_fractal	z;

	z.y = (map_scaling((t_scaling_value){.unscaled_num = y,
				.new_min = 2, .new_max = -2, .old_min = 0,
				.old_max = HEIGHT}) * fractal->zoom) + fractal->shift_y;
	return (z.y);
}

//z = z^2 + c 
//where c.x equal argv[2] (<value_1>) and c.y equal to argv[3] (<value_2>)
//z = point of interest (the pixel) and c = constant
void	render_julia(int x, int y, t_fractal *fractal)
{
	t_fractal	z;
	t_fractal	c;
	double		tmp;
	int			iter;
	int			color;

	z.x = julia_zx(x, fractal);
	z.y = julia_zy(y, fractal);
	c.x = fractal->x;
	c.y = fractal->y;
	iter = 0;
	while (iter < fractal->iteration_nb)
	{
		tmp = (z.x * z.x) - (z.y * z.y);
		z.y = (2 * z.x * z.y) + (c.y);
		z.x = tmp + c.x;
		if (((z.y * z.y) + (z.x * z.x)) > fractal->escape_value)
		{
			color = map_colo(iter, BLACK, WHITE, 15);
			ft_put_pixel(x, y, &fractal->image, color);
			return ;
		}
		iter++;
	}
	ft_put_pixel(x, y, &fractal->image, BLACK);
}
