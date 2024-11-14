/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:39:39 by cejin             #+#    #+#             */
/*   Updated: 2024/11/14 09:17:16 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

/*
If the point is on the cylinder
	--> the height is not negatif
	--> the height is not superior than the actual height of the cy
*/

//check if the point is actually on the cylinder

static float	_clamp_height(t_hit *obj, t_vec3 origin,
		t_vec3 direct, float root)
{
	t_vec3		hypotenuse;
	float		root_height;
	t_vec3		impact_point;
	t_cylinder	*cy;

	cy = obj->obj->cylinder;
	if (root < 0.f)
		return (-1);
	get_impact_point(&impact_point, origin, direct, root);
	vec3_sub_to(&hypotenuse, &impact_point, &cy->pos);
	root_height = dot_product(&hypotenuse, &cy->axis_vec);
	if (root_height < -cy->height / 2.0f
		|| root_height > cy->height / 2.0f)
	{
		return (-1);
	}
	return (root);
}

float	*get_roots(float a, float b, float c)
{
	float	delta;
	float	*roots;

	delta = discriminant_calcul(a, b, c);
	roots = quadratic_equation(a, b, delta);
	return (roots);
}

float	get_closest_point(float roots[2], t_hit *obj,
			t_vec3 origin, t_vec3 direc)
{
	float	point;

	obj->side = OUTSIDE;
	if (obj->obj->type == CYLINDER)
	{
		roots[0] = _clamp_height(obj, origin, direc, roots[0]);
		roots[1] = _clamp_height(obj, origin, direc, roots[1]);
	}
	point = compare_roots(roots, obj);
	free(roots);
	return (point);
}

float	compare_roots(float roots[2], t_hit *obj)
{
	if (roots[0] < 0.f && roots[1] < 0.f)
		return (-1);
	if (roots[0] < 0.f)
	{
		obj->side = INSIDE;
		return (roots[1]);
	}
	if (roots[1] < 0.f)
	{
		obj->side = INSIDE;
		return (roots[0]);
	}
	if (roots[0] < roots[1])
	{
		return (roots[0]);
	}
	return (roots[1]);
}
