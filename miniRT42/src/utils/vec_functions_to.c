/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_functions_to.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:42:59 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:43:01 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

t_vec3	*vec3_add_to(t_vec3 *dest, t_vec3 *vect1, t_vec3 *vect2)
{
	dest->x = vect1->x + vect2->x;
	dest->y = vect1->y + vect2->y;
	dest->z = vect1->z + vect2->z;
	return (dest);
}

t_vec3	*vec3_sub_to(t_vec3 *dest, t_vec3 *vect1, t_vec3 *vect2)
{
	dest->x = (vect1->x - vect2->x);
	dest->y = (vect1->y - vect2->y);
	dest->z = (vect1->z - vect2->z);
	return (dest);
}

t_vec3	*vec3_mult_to(t_vec3 *dest, t_vec3 *vect1, t_vec3 *vect2)
{
	dest->x = vect1->x * vect2->x;
	dest->y = vect1->y * vect2->y;
	dest->z = vect1->z * vect2->z;
	return (dest);
}

t_vec3	*vec3_mult_by_val_to(t_vec3 *dest, t_vec3 *vect1, float val)
{
	dest->x = vect1->x * val;
	dest->y = vect1->y * val;
	dest->z = vect1->z * val;
	return (dest);
}
