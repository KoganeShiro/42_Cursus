/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:37:56 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:37:58 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minirt.h"

/*
def:

P is a ray, defined P = O + D * t
C is a point that lies on the plane
V is the plane normal (unit length)

 To hit a plane we notice that:

	dot_product( P - C , V )

this mean that P-C vector
is perpendicular to the normal,
which is true when the point P lies on the plane

Obtained t is actually the distance of
the hit point from the ray origin

t = dot_product( -X, V ) / dot_product(D, V)

Before the division we should
check whether dot_product(D, V) is nonzero.

We can also check if the signs of
D|V and X|V are different (if not,
resulting t will be negative).

Surface normal vector at point P equals
to the plane normal, unless D|V is negative,
in which case N=-V.
*/

static float	_get_pl_intersec(t_plane *pl,
		t_vec3 origin, t_vec3 direct)
{
	float	d;
	t_vec3	normal;
	float	res;

	d = dot_product(&pl->direc, &direct);
	if (d <= 0)
		return (-1.f);
	vec3_sub_to(&normal, &pl->pos, &origin);
	res = dot_product(&normal, &pl->direc) / d;
	if (res < 0)
		return (0);
	return (res);
}

int	hit_plane(t_graphics *rt, t_hit *plane, bool light)
{
	float	distance;

	if (light == true)
	{
		distance = _get_pl_intersec(plane->obj->plane,
				rt->nearest_obj->impact_point,
				rt->nearest_obj->go_light_ray.direct);
	}
	else
	{
		distance = _get_pl_intersec(plane->obj->plane,
				rt->ray->origin, rt->ray->direct);
	}
	if (distance < 0 || distance == INFINITY
		|| distance == NAN || distance == -NAN)
	{
		return (EXIT_FAILURE);
	}
	plane->distance = distance;
	return (EXIT_SUCCESS);
}
