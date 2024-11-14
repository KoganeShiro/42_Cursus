/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:42:48 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:42:51 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

	//VECTOR NORMAL
	// produit vectoriel de deux vecteur 
	// (son résultat est un vecteur, à l'opposé du produit « scalaire »)
	// u=(ux, uy, uz) v=(vx, vy, vz)
	// res->x = uy*vz - uz*vy
	// res->y = uz*vz - ux*vz
	// res->z = ux*vy - uy*vx
	// SAME THE CROSS PRODUCT FUCK
	// le vecteur normal est le cross product de deux vecteurs directeur 

t_vec3	*_get_cy_normal_vec(t_vec3 *normal, t_graphics *rt)
{
	t_vec3	height;

	vec3_sub_to(normal, &rt->nearest_obj->impact_point,
		&rt->nearest_obj->obj->cylinder->pos);
	vec3_mult_by_val_to(&height,
		&rt->nearest_obj->obj->cylinder->axis_vec,
		dot_product(normal,
			&rt->nearest_obj->obj->cylinder->axis_vec));
	vec3_sub_to(normal, normal, &height);
	return (normal);
}

t_vec3	get_normal_vec(t_vec3 *normal, t_graphics *rt,
			t_objects_type type)
{
	if (type == SPHERE)
	{
		vec3_sub_to(normal, &rt->nearest_obj->impact_point,
			&rt->nearest_obj->obj->sphere->pos);
	}
	else if (type == PLANE)
	{
		vec3_cpy(normal, &rt->nearest_obj->obj->plane->direc);
	}
	else if (type == CYLINDER)
	{
		_get_cy_normal_vec(normal, rt);
	}
	return (*normal);
}

t_vec3	*vec3_cpy(t_vec3 *dest, t_vec3 *src)
{
	dest->x = src->x;
	dest->y = src->y;
	dest->z = src->z;
	return (dest);
}
