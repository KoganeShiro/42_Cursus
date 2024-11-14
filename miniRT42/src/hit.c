/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:37:32 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:37:36 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minirt.h"

t_hit	*hit_object(t_graphics *rt, t_geo_obj *object,
			t_hit *hit_what, bool light)
{
	hit_what->obj = object;
	hit_what->no_hit = false;
	if (object->type == SPHERE)
	{
		if (hit_sphere(rt, hit_what, light) == EXIT_FAILURE)
		{
			hit_what->no_hit = true;
		}
	}
	else if (object->type == PLANE)
	{
		if (hit_plane(rt, hit_what, light) == EXIT_FAILURE)
		{
			hit_what->no_hit = true;
		}
	}
	else if (object->type == CYLINDER)
	{
		if (hit_cylinder(rt, hit_what, light) == EXIT_FAILURE)
		{
			hit_what->no_hit = true;
		}
	}
	return (hit_what);
}
