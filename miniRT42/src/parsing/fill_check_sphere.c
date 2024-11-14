/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_check_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:45:50 by cejin             #+#    #+#             */
/*   Updated: 2024/11/13 15:42:39 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

/*
* split[0] = identifyer (sp)
* split[1] = pos (x,y,z)
* split[2] = diameter
* split[3] = RGB
*/

static int	_sphere_check(t_sphere *sp)
{
	if (in_range(sp->color) == false)
	{
		return (EXIT_FAILURE);
	}
	if (sp->diameter <= 0)
	{
		printf("The sp diameter should be > 0 !!\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	_set_sp_pos(t_sphere *sp, char *split)
{
	char	**pos;

	pos = ft_split(split, ',');
	if (has_right_args_nb(pos, 3) == true)
	{
		if (is_right_pos(pos) == EXIT_FAILURE)
		{
			return (free_tab(pos), EXIT_FAILURE);
		}
		sp->pos.x = ft_atof(pos[0]);
		sp->pos.y = ft_atof(pos[1]);
		sp->pos.z = ft_atof(pos[2]);
		free_tab(pos);
		return (EXIT_SUCCESS);
	}
	printf("ERROR: sphere %s\n", POS_FORMAT);
	return (free_tab(pos), EXIT_FAILURE);
}

static int	_fill_sp_value(t_geo_obj *sp,
	char **split)
{
	if (_set_sp_pos(sp->sphere, split[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (is_right_value(split[2], false, false, false) == false)
	{
		printf("ERROR: diameter should be a float\n");
		return (EXIT_FAILURE);
	}
	sp->sphere->diameter = ft_atof(split[2]);
	if (set_sp_rgb(sp->sphere, split[3]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	fill_sphere(char *line, t_geo_obj *sp)
{
	char	**split;

	if (sp == NULL)
		return (EXIT_FAILURE);
	split = ft_split(line, ' ');
	if (has_right_args_nb(split, 4) == true)
	{
		if (_fill_sp_value(sp, split) == EXIT_FAILURE)
		{
			return (free_tab(split), EXIT_FAILURE);
		}
		if (_sphere_check(sp->sphere) == EXIT_SUCCESS)
			return (free_tab(split), EXIT_SUCCESS);
		else
			return (free_tab(split), EXIT_FAILURE);
	}
	free_tab(split);
	printf("ERROR: sphere need 4 %s\n", ERR_WRONG_NB_ARG);
	return (EXIT_FAILURE);
}
