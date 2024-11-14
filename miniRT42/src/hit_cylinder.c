/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:38:20 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:38:22 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minirt.h"

/*
Def
C is the start cap point of the cylinder
V is a unit lenght vector that determines cylinder's axis
r is the cylinder's radius
maxm determines cylinder's end cap point
*/

static float	_get_cy_intersect(t_hit *cy,
		t_vec3 origin, t_vec3 direct)
{
	t_vec3	x;
	float	dv;
	float	a;
	float	b;
	float	c;

	vec3_sub_to(&x,
		&origin, &cy->obj->cylinder->pos);
	dv = dot_product(&direct,
			&cy->obj->cylinder->axis_vec);
	a = dot_product(&direct, &direct) - dv * dv;
	b = 2.f * (dot_product(&direct, &x)
			- dot_product(&direct,
				&cy->obj->cylinder->axis_vec)
			* dot_product(&x, &cy->obj->cylinder->axis_vec));
	c = dot_product(&x, &x)
		- pow(dot_product(&x, &cy->obj->cylinder->axis_vec), 2)
		- pow(cy->obj->cylinder->diameter / 2, 2);
	return (get_closest_point(get_roots(a, b, c), cy, origin, direct));
}

int	hit_cylinder(t_graphics *rt, t_hit *cylinder, bool light)
{
	float	distance;

	if (light == true)
	{
		distance = _get_cy_intersect(cylinder,
				rt->nearest_obj->impact_point,
				rt->nearest_obj->go_light_ray.direct);
	}
	else
	{
		distance = _get_cy_intersect(cylinder,
				rt->ray->origin, rt->ray->direct);
	}
	if (distance < 0 || distance == INFINITY
		|| distance == NAN || distance == -NAN)
	{
		return (EXIT_FAILURE);
	}
	cylinder->distance = distance;
	return (EXIT_SUCCESS);
}
