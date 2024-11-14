/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:37:05 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:37:10 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minirt.h"

int	cross_escape(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_init);
	return (0);
}

int	key_escape(int key, t_graphics *rt)
{
	if (key == XK_Escape)
	{
		destroy_mlx(rt->mlx);
		cleanup(rt);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	init_mlx(t_graphics *graphics, t_mlx *mlx)
{
	graphics->mlx = mlx;
	mlx->mlx_init = mlx_init();
	if (!mlx->mlx_init)
		return (EXIT_FAILURE);
	mlx->mlx_window = mlx_new_window(mlx->mlx_init, WIDTH, HEIGHT, WINDOW_NAME);
	if (!mlx->mlx_window)
		return (EXIT_FAILURE);
	mlx->image_ptr = mlx_new_image(mlx->mlx_init, WIDTH, HEIGHT);
	if (!mlx->image_ptr)
		return (EXIT_FAILURE);
	mlx->addr = mlx_get_data_addr(mlx->image_ptr,
			&mlx->img_bpp, &mlx->line_len, &mlx->endian);
	if (!mlx->addr)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	run_mlx(t_mlx *mlx, t_graphics *rt)
{
	mlx_destroy_image(mlx->mlx_init, mlx->image_ptr);
	mlx_hook(mlx->mlx_window,
		DestroyNotify,
		StructureNotifyMask, cross_escape, mlx);
	mlx_hook(mlx->mlx_window, KeyPress, KeyPressMask, key_escape, rt);
	mlx_loop(mlx->mlx_init);
}

void	destroy_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_init, mlx->mlx_window);
	mlx_destroy_display(mlx->mlx_init);
	free(mlx->mlx_init);
}
