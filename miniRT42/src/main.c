/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:03:10 by cejin             #+#    #+#             */
/*   Updated: 2024/10/24 17:17:01 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minirt.h"

int	main(int argc, char **argv)
{
	t_graphics	rt;
	t_mlx		mlx;

	if (argc != 2)
	{
		printf("Usage: ./miniRT file.rt");
		return (EXIT_FAILURE);
	}
	if (init_data(&rt, &mlx, argv[1]) == EXIT_SUCCESS)
	{
		raytracing(&rt);
		run_mlx(&mlx, &rt);
		destroy_mlx(&mlx);
	}
	cleanup(&rt);
	return (0);
}
