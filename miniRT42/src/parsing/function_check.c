/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:54:53 by cejin             #+#    #+#             */
/*   Updated: 2024/10/21 14:02:18 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

//check if vec length is between -1 and 1
//range [-1 1]
bool	normalized_check(t_vec3 vec)
{
	normalized(&vec);
	return (true);
}

bool	in_range(t_color color)
{
	if (!(color.r >= 0 && color.r <= 255))
	{
		printf("r not in range: [%f]\n", color.r);
		return (false);
	}
	if (!(color.g >= 0 && color.g <= 255))
	{
		printf("g not in range: [%f]\n", color.g);
		return (false);
	}
	if (!(color.b >= 0 && color.b <= 255))
	{
		printf("b not in range: [%f]\n", color.b);
		return (false);
	}
	return (true);
}

bool	light_ratio_check(t_graphics *rt, t_objects_type obj)
{
	if (obj == LIGHT)
	{
		if (rt->light->brightness_ratio >= 0.f
			&& rt->light->brightness_ratio <= 1.f)
		{
			return (true);
		}
		printf("ERROR: Light brightness ratio [0;1] !!\n");
	}
	else if (obj == AMBIENT)
	{
		if (rt->ambient->lightness_ratio >= 0.f
			&& rt->ambient->lightness_ratio <= 1.f)
		{
			return (true);
		}
		printf("ERROR: Ambient lightness ratio [0;1] !!\n");
	}
	return (false);
}
