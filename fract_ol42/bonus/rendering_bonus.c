/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:15:56 by cejin             #+#    #+#             */
/*   Updated: 2023/12/21 16:11:25 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	render_fractol(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (!ft_strcmp(fractal->name, "mandelbrot"))
				render_mandelbrot(x, y, fractal);
			else if (!ft_strcmp(fractal->name, "julia"))
				render_julia(x, y, fractal);
			else if (!ft_strcmp(fractal->name, "burning_ship"))
				render_burning_ship(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->image.image_ptr, 0, 0);
}
