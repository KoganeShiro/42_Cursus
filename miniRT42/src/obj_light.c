/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:36:56 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:36:58 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minirt.h"

// LAMBERT shading model
//Find the light direction.
//Calculate the cosine of
	//the angle between the light ray and the surface normal.
//Multiply the cosine angle by the brightness ratio of the light.
//Add the result to the color of the intersection point.
//Finally, add this value to the ambient color.

static t_vec3	_light_ratio(t_graphics *rt,
		t_vec3 *normal, t_vec3 color)
{
	float	light;
	float	ratio;

	ratio = 0;
	light = 0;
	ratio = dot_product(normal,
			&rt->nearest_obj->go_light_ray.direct);
	if (ratio < 0)
		ratio = -ratio;
	ratio = pow(ratio, 3);
	light = ratio * rt->light->brightness_ratio;
	if (light >= 0 && light <= 1)
	{
		vec3_mult_by_val_to(&color,
			init_vec(&color, 255, 255, 255), light);
	}
	return (color);
}

t_vec3	sphere_light(t_graphics *rt, t_hit *hit, t_vec3 color)
{
	t_vec3	normal;
	float	light;
	float	ratio;

	ratio = 0;
	light = 0;
	vec3_sub_to(&normal,
		&rt->nearest_obj->impact_point,
		&rt->nearest_obj->obj->sphere->pos);
	if (rt->nearest_obj->side == INSIDE)
		inverse_vect(&normal, &normal);
	normalized(&normal);
	normalized(&hit->go_light_ray.direct);
	return (_light_ratio(rt, &normal, color));
}

t_vec3	plane_light(t_graphics *rt, t_hit *hit, t_vec3 color)
{
	t_vec3	normal;
	float	light;
	float	ratio;

	ratio = 0;
	light = 0;
	vec3_cpy(&normal, &rt->nearest_obj->obj->plane->direc);
	normalized(&normal);
	normalized(&hit->go_light_ray.direct);
	return (_light_ratio(rt, &normal, color));
}

t_vec3	cylinder_light(t_graphics *rt, t_hit *hit, t_vec3 color)
{
	t_vec3	normal;

	get_normal_vec(&normal, rt, CYLINDER);
	if (rt->nearest_obj->side == INSIDE)
		inverse_vect(&normal, &normal);
	normalized(&normal);
	normalized(&hit->go_light_ray.direct);
	return (_light_ratio(rt, &normal, color));
}
