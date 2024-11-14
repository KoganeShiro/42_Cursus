/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:38:33 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:38:36 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minirt.h"

int	get_sphere_color(t_graphics *rt, t_hit *nearest)
{
	int		pixel_color;
	t_color	tmp;
	t_vec3	light;
	t_vec3	color;

	tmp.r = 0;
	tmp.g = 0;
	tmp.b = 0;
	init_vec(&light, 0, 0, 0);
	init_vec(&color, 0, 0, 0);
	send_light_ray(rt, nearest);
	vec3_cpy(&color, &nearest->obj->sphere->color_vec);
	light = calculate_glb_light(rt, nearest, color);
	vec3_add_to(&color, &color, &light);
	pixel_color = color_in_range(
			*conv_struc_vec3_to_color(&tmp, &color));
	return (pixel_color);
}

int	get_plane_color(t_graphics *rt, t_hit *nearest)
{
	int		pixel_color;
	t_color	tmp;
	t_vec3	light;
	t_vec3	color;

	tmp.r = 0;
	tmp.g = 0;
	tmp.b = 0;
	init_vec(&light, 0, 0, 0);
	init_vec(&color, 0, 0, 0);
	send_light_ray(rt, nearest);
	vec3_cpy(&color, &nearest->obj->plane->color_vec);
	light = calculate_glb_light(rt, nearest, color);
	vec3_add_to(&color, &color, &light);
	pixel_color = color_in_range(
			*conv_struc_vec3_to_color(&tmp, &color));
	return (pixel_color);
}

int	get_cylinder_color(t_graphics *rt, t_hit *nearest)
{
	int		pixel_color;
	t_color	tmp;
	t_vec3	light;
	t_vec3	color;

	tmp.r = 0;
	tmp.g = 0;
	tmp.b = 0;
	init_vec(&light, 0, 0, 0);
	init_vec(&color, 0, 0, 0);
	send_light_ray(rt, nearest);
	vec3_cpy(&color, &nearest->obj->cylinder->color_vec);
	light = calculate_glb_light(rt, nearest, color);
	vec3_add_to(&color, &color, &light);
	pixel_color = color_in_range(
			*conv_struc_vec3_to_color(&tmp, &color));
	return (pixel_color);
}
