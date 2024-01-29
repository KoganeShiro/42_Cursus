/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:15:50 by cejin             #+#    #+#             */
/*   Updated: 2023/12/21 11:35:29 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	data_value(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iteration_nb = 10;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((2 == argc && !ft_strcmp(argv[1], "mandelbrot"))
		|| (4 == argc && !ft_strcmp(argv[1], "julia")))
	{
		fractal.name = argv[1];
		if (!ft_strcmp(fractal.name, "julia"))
		{
			fractal.x = ft_atodbl(argv[2]);
			fractal.y = ft_atodbl(argv[3]);
		}
		fractol_init(&fractal);
		render_fractol(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_printf(ERROR_MESSAGE);
		exit(EXIT_FAILURE);
	}
}
