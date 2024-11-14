/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:39:20 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:39:21 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

int	convert_color_struct_to_int(t_color color)
{
	int	rgb_color;

	rgb_color = ((int)color.r) << 16
		| ((int)color.g) << 8
		| ((int)color.b);
	return (rgb_color);
}

//if -nb then it's == 0
//if nb>255 then it's == 255

static float	_make_it_in_range(float nb)
{
	if (nb < 0.f)
		return (0);
	if (nb > 255.f)
		return (255);
	return (nb);
}

float	color_in_range(t_color color)
{
	color.r = _make_it_in_range(color.r / 1.7);
	color.g = _make_it_in_range(color.g / 1.7);
	color.b = _make_it_in_range(color.b / 1.7);
	return (convert_color_struct_to_int(color));
}

t_vec3	*init_vec(t_vec3 *vec, float x, float y, float z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}
