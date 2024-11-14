/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:38:44 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:38:45 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minirt.h"

static t_hit	*_return_nearest(t_graphics *rt,
			t_hit *hit_what, t_geo_obj *tmp)
{
	hit_what->no_hit = false;
	hit_what->distance = INFINITY;
	hit_what = hit_object(rt, tmp, hit_what, false);
	if (hit_what->no_hit == false)
	{
		if (hit_what->distance < rt->nearest_obj->distance)
		{
			*rt->nearest_obj = *hit_what;
		}
	}
	return (rt->nearest_obj);
}

float	get_nearest_obj(t_graphics *rt)
{
	t_geo_obj	*tmp;
	t_hit		hit_what;
	t_color		bg_color;

	tmp = rt->lst_obj;
	rt->nearest_obj->no_hit = true;
	rt->nearest_obj->distance = INFINITY;
	bg_color = (t_color){0};
	while (tmp != NULL)
	{
		rt->nearest_obj = _return_nearest(rt, &hit_what, tmp);
		tmp = tmp->next;
	}
	if (rt->nearest_obj->no_hit == true)
	{
		return (get_bg_color(bg_color));
	}
	return (get_color(rt, rt->nearest_obj));
}
