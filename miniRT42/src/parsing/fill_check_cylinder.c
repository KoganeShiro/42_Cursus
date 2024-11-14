/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_check_cylinder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:41:52 by cejin             #+#    #+#             */
/*   Updated: 2024/11/14 10:00:08 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

/*
* split[0] = identifyer (cy)
* split[1] = pos (x,y,z)
* split[2] = normalized normal vec (axis of cylinder)
* split[3] = diameter
* split[4] = height
* split[5] = RGB
*/

int	cylinder_check(t_cylinder *cylinder)
{
	if (normalized_check(cylinder->axis_vec) == false)
	{
		printf("Cylinder %s\n", VEC_NOT_NORMALIZED);
		return (EXIT_FAILURE);
	}
	if (in_range(cylinder->color) == false)
	{
		printf("Cylinder %s\n", WRONG_RGB_RANGE);
		return (EXIT_FAILURE);
	}
	if (cylinder->height <= 0)
	{
		printf("The cy heigh should be > 0 !!\n");
		return (EXIT_FAILURE);
	}
	if (cylinder->diameter <= 0)
	{
		printf("The cy diameter should be > 0 !!\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	set_cy_pos(t_cylinder *cy, char *split)
{
	char	**pos;

	pos = ft_split(split, ',');
	if (has_right_args_nb(pos, 3) == true)
	{
		if (is_right_pos(pos) == EXIT_FAILURE)
		{
			return (free_tab(pos), EXIT_FAILURE);
		}
		cy->pos.x = ft_atof(pos[0]);
		cy->pos.y = ft_atof(pos[1]);
		cy->pos.z = ft_atof(pos[2]);
		free_tab(pos);
		return (EXIT_SUCCESS);
	}
	free_tab(pos);
	printf("ERROR: cylinder %s\n", POS_FORMAT);
	return (EXIT_FAILURE);
}

int	fill_diameter_height(t_cylinder *cy, char **split)
{
	if (is_right_value(split[3], false, false, false) == false)
	{
		printf("ERROR: CY diameter should be a float\n");
		return (EXIT_FAILURE);
	}
	cy->diameter = ft_atof(split[3]);
	if (is_right_value(split[4], false, false, false) == false)
	{
		printf("ERROR: CY height should be a float\n");
		return (EXIT_FAILURE);
	}
	cy->height = ft_atof(split[4]);
	return (EXIT_SUCCESS);
}

int	fill_cylinder(char *line, t_geo_obj *cy)
{
	char	**split;

	split = ft_split(line, ' ');
	if (has_right_args_nb(split, 6) == true)
	{
		if (set_cy_pos(cy->cylinder, split[1]) == EXIT_FAILURE)
			return (free_tab(split), EXIT_FAILURE);
		if (set_normalized_cy_vect(cy->cylinder, split[2]) == EXIT_FAILURE)
			return (free_tab(split), EXIT_FAILURE);
		if (fill_diameter_height(cy->cylinder, split) == EXIT_FAILURE)
			return (free_tab(split), EXIT_FAILURE);
		if (set_cy_rgb(cy->cylinder, split[5]) == EXIT_FAILURE)
			return (free_tab(split), EXIT_FAILURE);
		if (cylinder_check(cy->cylinder) == EXIT_SUCCESS)
			return (free_tab(split), EXIT_SUCCESS);
		else
			return (free_tab(split), EXIT_FAILURE);
	}
	printf("ERROR: cylinder need  %s\n", ERR_WRONG_NB_ARG);
	return (free_tab(split), EXIT_FAILURE);
}
