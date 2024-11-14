/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:37:45 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:37:46 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minirt.h"

/*
|P - C|^2 - r^2 = 0
	where P is the point on the sphere(Px, Py, Pz)

P can be describe as Origin + distance (often refer to t)
						* Direction

|O + tD - C|^2 - r^2 = 0
	where O is the center point of the sphere
		  t is the distance (diameter/2)
		  D is the direction

if we expend this equation, we will get
	a second degree equation (at^2 + bt +c)

With that we know that
a = D.D
	= 1 (bc vect normal)
b = 2(O.D)
	= dot_product of ray->ori = center_of_sp and ray->dir = intersec_point
c = O.O - r^2
	= 

delta = b^2 - 4ac

quadratic equation
if delta > 0 there are two roots (so two intersection point)
	d = (-b + sqrt(delta))/2a
	d = (-b - sqrt(delta))/2a

if delta == 0 there is one root (so one intersection)
	d = -b/2a

if delta < 0, there is no root (so no intersection)
*/

static float	_get_sp_intersec(t_hit *sp,
	t_vec3 origin, t_vec3 direct)
{
	float	a;
	float	b;
	float	c;
	float	r_square;
	t_vec3	sp_origin;

	a = dot_product(&direct, &direct);
	vec3_sub_to(&sp_origin,
		&origin, &sp->obj->sphere->pos);
	b = 2 * dot_product(&direct, &sp_origin);
	r_square = pow(sp->obj->sphere->diameter / 2, 2.);
	c = dot_product(&sp_origin, &sp_origin) - r_square;
	return (get_closest_point(get_roots(a, b, c), sp, origin, direct));
}

int	hit_sphere(t_graphics *rt, t_hit *sphere, bool light)
{
	float	distance;

	if (light == true)
	{
		distance = _get_sp_intersec(sphere,
				rt->nearest_obj->impact_point,
				rt->nearest_obj->go_light_ray.direct);
	}
	else
	{
		distance = _get_sp_intersec(sphere,
				rt->ray->origin, rt->ray->direct);
	}
	if (distance < 0 || distance == INFINITY
		|| distance == NAN || distance == -NAN)
	{
		return (EXIT_FAILURE);
	}
	sphere->distance = distance;
	return (EXIT_SUCCESS);
}
