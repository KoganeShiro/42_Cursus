/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glb_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:21:47 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:58:00 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minirt.h"

//add ratio * rgb blanc then add to pixel final
	//ambiant color * ratio ambiant

t_vec3	ambiant_light_vec(t_graphics *rt)
{
	t_vec3	color;

	init_vec(&color, 0, 0, 0);
	vec3_mult_by_val_to(&color,
		&rt->ambient->color_vec,
		rt->ambient->lightness_ratio);
	return (color);
}

t_vec3	calculate_glb_light(t_graphics *rt, t_hit *hit,
			t_vec3 light)
{
	t_vec3	glb_light;
	t_vec3	ambiant_light;

	init_vec(&ambiant_light, 0, 0, 0);
	ambiant_light = ambiant_light_vec(rt);
	if (rt->nearest_obj->got_light == false)
		light = (t_vec3){0};
	else
	{
		if (rt->nearest_obj->obj->type == SPHERE)
			light = sphere_light(rt, hit, light);
		else if (rt->nearest_obj->obj->type == PLANE)
			light = plane_light(rt, hit, light);
		else if (rt->nearest_obj->obj->type == CYLINDER)
			light = cylinder_light(rt, hit, light);
	}
	vec3_add_to(&glb_light, &light, &ambiant_light);
	return (glb_light);
}
