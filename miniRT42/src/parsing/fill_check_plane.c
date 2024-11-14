/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_check_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:42:02 by cejin             #+#    #+#             */
/*   Updated: 2024/11/14 10:10:16 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

/*
* split[0] = identifyer (pl)
* split[1] = pos (x,y,z)
* split[2] = normalized normal vector
* split[3] = RGB
*/

static int	_check_plane(t_plane *plane)
{
	if (normalized_check(plane->direc) == false)
	{
		printf("Plane %s\n", VEC_NOT_NORMALIZED);
		return (EXIT_FAILURE);
	}
	if (in_range(plane->color) == false)
	{
		printf("Plane %s\n", WRONG_RGB_RANGE);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	_set_pl_pos(t_plane *pl, char *split)
{
	char	**pos;

	pos = ft_split(split, ',');
	if (has_right_args_nb(pos, 3) == true)
	{
		if (is_right_pos(pos) == EXIT_FAILURE)
		{
			return (free_tab(pos), EXIT_FAILURE);
		}
		pl->pos.x = ft_atof(pos[0]);
		pl->pos.y = ft_atof(pos[1]);
		pl->pos.z = ft_atof(pos[2]);
		free_tab(pos);
		return (EXIT_SUCCESS);
	}
	free_tab(pos);
	printf("ERROR: plane %s\n", POS_FORMAT);
	return (EXIT_FAILURE);
}

static int	_fill_sp_value(t_geo_obj *pl,
	char **split)
{
	if (_set_pl_pos(pl->plane, split[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (set_normalized_pl_vect(pl->plane, split[2]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (set_pl_rgb(pl->plane, split[3]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	fill_plane(char *line, t_geo_obj *pl)
{
	char	**split;

	if (pl == NULL)
		return (EXIT_FAILURE);
	split = ft_split(line, ' ');
	if (has_right_args_nb(split, 4) == true)
	{
		if (_fill_sp_value(pl, split) == EXIT_FAILURE)
		{
			return (free_tab(split), EXIT_FAILURE);
		}
		if (_check_plane(pl->plane) == EXIT_SUCCESS)
			return (free_tab(split), EXIT_SUCCESS);
		else
			return (free_tab(split), EXIT_FAILURE);
	}
	free_tab(split);
	printf("ERROR: plane need 4 %s\n", ERR_WRONG_NB_ARG);
	return (EXIT_FAILURE);
}
