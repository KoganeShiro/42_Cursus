/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:48:31 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:48:33 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

t_vec3	*vec3_add_val(t_vec3 *vect, float val)
{
	vect->x += val;
	vect->y += val;
	vect->z += val;
	return (vect);
}

t_vec3	*vec3_substract_val(t_vec3 *vect, float val)
{
	vect->x = vect->x - val;
	vect->y = vect->y - val;
	vect->z = vect->z - val;
	return (vect);
}

t_vec3	*inverse_vect(t_vec3 *dest, t_vec3 *src)
{
	dest->x = -(src->x);
	dest->y = -(src->y);
	dest->z = -(src->z);
	return (dest);
}

float	vect_norme(t_vec3 *vect)
{
	float	len;

	len = sqrt (pow((vect->x), (2))
			+ pow((vect->y), (2)) + pow((vect->z), (2)));
	return (len);
}

float	dist_between(t_vec3 *vect1, t_vec3 *vect2)
{
	float	dist;

	dist = sqrt (pow((vect1->x - vect2->x), (2))
			+ pow((vect1->y - vect2->y), (2))
			+ pow((vect1->z - vect2->z), (2)));
	return (dist);
}
