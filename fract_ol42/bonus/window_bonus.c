/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:16:04 by cejin             #+#    #+#             */
/*   Updated: 2023/12/21 11:57:14 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

//Will open a window and show the created image of the choosen fractal
int	fractol_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	ft_check_errors(fractal);
	fractal->image.pixels_ptr = mlx_get_data_addr(
			fractal->image.image_ptr,
			&fractal->image.bits_per_pixel,
			&fractal->image.line_len,
			&fractal->image.endian);
	hook_event(fractal);
	data_value(fractal);
	return (0);
}

//int (*f)(void *param)
int	handle_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.image_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_check_errors(t_fractal *fractal)
{
	if (fractal->mlx_connection == NULL)
		exit(EXIT_FAILURE);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(EXIT_FAILURE);
	}
	fractal->image.image_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (fractal->image.image_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(EXIT_FAILURE);
	}
}
