/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:44:40 by cejin             #+#    #+#             */
/*   Updated: 2024/11/13 15:29:17 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

int	is_right_pos(char **pos)
{
	if (is_right_value(pos[0], false, false, false) == false)
	{
		printf("ERROR (pos x: '%s' not a float)\n", pos[0]);
		return (EXIT_FAILURE);
	}
	if (is_right_value(pos[1], false, false, false) == false)
	{
		printf("ERROR (pos y: '%s' not a float)\n", pos[1]);
		return (EXIT_FAILURE);
	}
	if (is_right_value(pos[2], false, false, false) == false)
	{
		printf("ERROR (pos z: '%s' not a float)\n", pos[2]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	_cam_pos(t_graphics *rt, char **pos)
{
	rt->camera->pos.x = ft_atof(pos[0]);
	rt->camera->pos.y = ft_atof(pos[1]);
	rt->camera->pos.z = ft_atof(pos[2]);
}

static void	_light_pos(t_graphics *rt, char **pos)
{
	rt->light->pos.x = ft_atof(pos[0]);
	rt->light->pos.y = ft_atof(pos[1]);
	rt->light->pos.z = ft_atof(pos[2]);
}

int	set_position(t_graphics *rt, t_objects_type obj, char *split)
{
	char	**pos;

	pos = ft_split(split, ',');
	if (has_right_args_nb(pos, 3) == true)
	{
		if (is_right_pos(pos) == EXIT_FAILURE)
			return (free_tab(pos), EXIT_FAILURE);
		if (obj == CAMERA)
			_cam_pos(rt, pos);
		else if (obj == LIGHT)
			_light_pos(rt, pos);
		free_tab(pos);
		return (EXIT_SUCCESS);
	}
	free_tab(pos);
	printf("Error, pos should be in this format [x,y,z]\n");
	return (EXIT_FAILURE);
}
