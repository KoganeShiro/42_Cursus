/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:15:24 by cejin             #+#    #+#             */
/*   Updated: 2023/12/21 17:35:41 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_put_pixel(int x, int y, t_img *image, int color)
{
	int	offset;

	offset = (y * image->line_len) + (x * (image->bits_per_pixel / 8));
	*(unsigned int *)(image->pixels_ptr + offset) = color;
}

double	map_scaling(t_scaling_value num)
{
	return ((num.new_max - num.new_min)
		* (num.unscaled_num - num.old_min)
		/ (num.old_max - num.old_min)
		+ num.new_min);
}

double	map_colo(double unscaled_num, double new_min,
					double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num) / (old_max) + new_min);
}
