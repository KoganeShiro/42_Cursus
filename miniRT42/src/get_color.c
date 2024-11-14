/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:38:51 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:38:55 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minirt.h"

void	init_color_vec(t_graphics *rt)
{
	t_geo_obj	*tmp;

	tmp = rt->lst_obj;
	while (tmp != NULL)
	{
		if (tmp->type == SPHERE)
			conv_struct_color_to_vec3(
				&tmp->sphere->color_vec, &tmp->sphere->color);
		else if (tmp->type == PLANE)
			conv_struct_color_to_vec3(
				&tmp->plane->color_vec, &tmp->plane->color);
		else if (tmp->type == CYLINDER)
			conv_struct_color_to_vec3(
				&tmp->cylinder->color_vec, &tmp->cylinder->color);
		tmp = tmp->next;
	}
	conv_struct_color_to_vec3(&rt->ambient->color_vec,
		&rt->ambient->color);
}

int	get_bg_color(t_color color)
{
	int	bg_color;

	color.r = 1;
	color.g = 87;
	color.b = 155;
	bg_color = convert_color_struct_to_int(color);
	return (bg_color);
}

int	get_color(t_graphics *rt, t_hit *nearest)
{
	int	color;

	color = 0;
	if (nearest->obj->type == SPHERE)
	{
		color = get_sphere_color(rt, nearest);
	}
	else if (nearest->obj->type == PLANE)
	{
		color = get_plane_color(rt, nearest);
	}
	else if (nearest->obj->type == CYLINDER)
	{
		color = get_cylinder_color(rt, nearest);
	}
	return (color);
}
