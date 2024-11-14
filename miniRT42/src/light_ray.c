/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:37:23 by cejin             #+#    #+#             */
/*   Updated: 2024/11/13 14:11:38 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minirt.h"

//need to send a ray 
//origin = on the sp, direct = light
//
//pos d'origine cam + (direction of the first ray * dist cam objet)
//distance calculate by the quadratic equation
//rt->ray->direct is a vec3 how to have a float ?
//vec3_mult_by_val_to(t_vec3 *dest, t_vec3 *vect1, float val);

t_vec3	*get_impact_point(t_vec3 *impact_point,
	t_vec3 origin, t_vec3 direct, float distance)
{
	t_vec3	tmp;

	tmp.x = 0;
	tmp.y = 0;
	tmp.z = 0;
	vec3_add_to(impact_point,
		&origin, vec3_mult_by_val_to(&tmp, &direct,
			distance));
	return (impact_point);
}

static void	_shift_impact_point(t_graphics *rt)
{
	t_vec3	normal;

	normal = get_normal_vec(&normal, rt, rt->nearest_obj->obj->type);
	normalized(&normal);
	vec3_mult_by_val_to(&normal,
		&normal, DELTA);
	vec3_add_to(&rt->nearest_obj->impact_point,
		&rt->nearest_obj->impact_point, &normal);
}

static void	_does_light_hit_obj(t_graphics *rt, t_hit *obj_found)
{
	t_geo_obj	*tmp;
	t_hit		hit_what;

	hit_what = (t_hit){0};
	tmp = rt->lst_obj;
	rt->nearest_obj->got_light = false;
	while (tmp != NULL)
	{
		obj_found = hit_object(rt, tmp, &hit_what, true);
		if (obj_found->no_hit == false)
		{
			if (obj_found->distance
				>= dist_between(&rt->light->pos,
					&obj_found->impact_point))
			{
				obj_found->no_hit = true;
			}
			else
				break ;
		}
		tmp = tmp->next;
	}
	if (obj_found->no_hit == true)
		rt->nearest_obj->got_light = true;
}

void	send_light_ray(t_graphics *rt, t_hit *nearest)
{
	t_hit	obj;

	get_impact_point(&rt->nearest_obj->impact_point,
		rt->ray->origin, rt->ray->direct, rt->nearest_obj->distance);
	_shift_impact_point(rt);
	nearest->go_light_ray.origin = rt->nearest_obj->impact_point;
	vec3_sub_to
		(&rt->nearest_obj->go_light_ray.direct,
		&rt->light->pos,
		&rt->nearest_obj->impact_point);
	normalized(&rt->nearest_obj->go_light_ray.direct);
	_does_light_hit_obj(rt, &obj);
}
