/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:50:20 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:53:28 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

static int	_init_struct(t_graphics *rt)
{
	rt->light = (t_light *)ft_calloc(1, sizeof(t_light));
	if (rt->light == NULL)
		return (EXIT_FAILURE);
	rt->camera = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (rt->camera == NULL)
		return (EXIT_FAILURE);
	rt->ambient = (t_ambient *)ft_calloc(1, sizeof(t_ambient));
	if (rt->ambient == NULL)
		return (EXIT_FAILURE);
	rt->nearest_obj = (t_hit *)ft_calloc(1, sizeof(t_hit));
	if (rt->nearest_obj == NULL)
		return (EXIT_FAILURE);
	rt->viewport = (t_viewport *)ft_calloc(1, sizeof(t_viewport));
	if (rt->viewport == NULL)
		return (EXIT_FAILURE);
	rt->ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
	if (rt->ray == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	create_linked_list(t_graphics *rt)
{
	rt->lst_obj = (t_geo_obj *)ft_calloc(1, sizeof(t_geo_obj));
	if (rt->lst_obj == NULL)
		return (EXIT_FAILURE);
	rt->lst_obj->type = SPHERE;
	rt->lst_obj->next = NULL;
	return (EXIT_SUCCESS);
}

int	init_data(t_graphics *rt, t_mlx *mlx, char *file)
{
	if (_init_struct(rt) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	rt->lst_obj = NULL;
	rt->has_require_obj = 0;
	rt->viewport->vh = HEIGHT;
	rt->viewport->vw = WIDTH;
	if (parse_file(file, rt) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	if (init_mlx(rt, mlx) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	init_color_vec(rt);
	return (EXIT_SUCCESS);
}
