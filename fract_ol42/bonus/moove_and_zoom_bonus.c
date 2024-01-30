/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_and_zoom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:17:18 by cejin             #+#    #+#             */
/*   Updated: 2023/12/22 12:34:45 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

//int (*f)(int keycode, void *param)
int	keyboard_event(int key, t_fractal *fractal)
{
	if (key == XK_Escape)
		handle_close(fractal);
	else if (key == XK_Right)
		fractal->shift_x += (0.15 * fractal->zoom);
	else if (key == XK_Left)
		fractal->shift_x -= (0.15 * fractal->zoom);
	else if (key == XK_Up)
		fractal->shift_y += (0.15 * fractal->zoom);
	else if (key == XK_Down)
		fractal->shift_y -= (0.15 * fractal->zoom);
	else if (key == XK_minus)
		fractal->iteration_nb -= 3;
	else if (key == XK_equal)
		fractal->iteration_nb += 3;
	else
		keyboard_event2(key, fractal);
	render_fractol(fractal);
	return (0);
}

int	keyboard_event2(int key, t_fractal *fractal)
{
	if (key == XK_w)
		fractal->x += 0.1;
	else if (key == XK_a)
		fractal->x -= 0.1;
	else if (key == XK_s)
		fractal->y += 0.1;
	else if (key == XK_d)
		fractal->y -= 0.1;
	else if (key == XK_r)
	{
		fractal->x = 0.0;
		fractal->y = 0.0;
		fractal->zoom = 1.0;
	}
	return (0);
}

//int (*f)(int button, int x, int y, void *param)
int	handle_mouse_zoom(int button, int x, int y, t_fractal *fractal)
{
	double	x_under;
	double	y_under;
	double	x_scaled;
	double	y_scaled;

	x_under = (((float)x - WIDTH / 2.0)
			/ (WIDTH / 4.0)) * fractal->zoom + fractal->shift_x;
	y_under = (((float)y - HEIGHT / 2.0)
			/ (HEIGHT / 4.0)) * fractal->zoom + fractal->shift_y;
	if (button == Button4)
	{
		fractal->zoom *= 0.95;
		x_scaled = (((float)x - WIDTH / 2.0)
				/ (WIDTH / 4.0)) * fractal->zoom + fractal->shift_x;
		y_scaled = (((float)y - HEIGHT / 2.0)
				/ (HEIGHT / 4.0)) * fractal->zoom + fractal->shift_y;
		fractal->shift_x += x_under - x_scaled;
		fractal->shift_y += y_scaled - y_under;
	}
	else if (button == Button5)
		fractal->zoom *= 1.05;
	render_fractol(fractal);
	return (0);
}

//mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param)
void	hook_event(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window,
		KeyPress, KeyPressMask,
		keyboard_event, fractal);
	mlx_hook(fractal->mlx_window,
		ButtonPress, ButtonPressMask,
		handle_mouse_zoom, fractal);
	mlx_hook(fractal->mlx_window,
		DestroyNotify, StructureNotifyMask,
		handle_close, fractal);
}
