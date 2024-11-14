/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_equations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:39:30 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:39:31 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

float	discriminant_calcul(float a, float b, float c)
{
	float	res;

	if (a == 0)
		res = -1;
	else
		res = b * b - 4 * a * c;
	return (res);
}

float	*quadratic_equation(float a, float b, float delta)
{
	float	*roots;

	roots = (float *) malloc(2 * sizeof(float));
	if (delta < 0)
	{
		roots[0] = -1;
		roots[1] = -1;
	}
	else if (delta == 0)
	{
		roots[0] = -(b) / (2 * a);
		roots[1] = roots[0];
	}
	else
	{
		roots[0] = (-(b) + sqrt(delta)) / (2 * a);
		roots[1] = (-(b) - sqrt(delta)) / (2 * a);
	}
	return (roots);
}

t_vec3	*cross_product(t_vec3 *dest, t_vec3 *vect1, t_vec3 *vect2)
{
	dest->x = (vect1->y * vect2->z) - (vect1->z * vect2->y);
	dest->y = (vect1->z * vect2->x) - (vect1->x * vect2->z);
	dest->z = (vect1->x * vect2->y) - (vect1->y * vect2->x);
	return (dest);
}

float	dot_product(t_vec3 *vect1, t_vec3 *vect2)
{
	float	res;

	res = (vect1->x * vect2->x) + (vect1->y * vect2->y) + (vect1->z * vect2->z);
	return (res);
}

t_vec3	*normalized(t_vec3 *vec)
{
	float	len;

	len = vect_norme(vec);
	vec->x = (vec->x / len);
	vec->y = (vec->y / len);
	vec->z = (vec->z / len);
	return (vec);
}
