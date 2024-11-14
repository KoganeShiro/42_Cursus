/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_normalized_vec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:46:47 by cejin             #+#    #+#             */
/*   Updated: 2024/10/21 10:06:38 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

static int	_is_right_vec(char **vec)
{
	if (is_right_value(vec[0], false, false, false) == false)
	{
		printf("ERROR: (vec x) '%s' should be a float\n", vec[0]);
		return (false);
	}
	if (is_right_value(vec[1], false, false, false) == false)
	{
		printf("ERROR: (vec y) '%s' should be a float\n", vec[1]);
		return (false);
	}
	if (is_right_value(vec[2], false, false, false) == false)
	{
		printf("ERROR: (vec z) '%s' should be a float\n", vec[2]);
		return (false);
	}
	return (true);
}

int	set_normalized_pl_vect(t_plane *pl, char *split)
{
	char	**vec;

	vec = ft_split(split, ',');
	if (has_right_args_nb(vec, 3) == true)
	{
		if (_is_right_vec(vec) == false)
		{
			return (free_tab(vec), EXIT_FAILURE);
		}
		pl->direc.x = ft_atof(vec[0]);
		pl->direc.y = ft_atof(vec[1]);
		pl->direc.z = ft_atof(vec[2]);
		normalized(&pl->direc);
		return (free_tab(vec), EXIT_SUCCESS);
	}
	printf("ERROR: normalized plane vec %s\n", VEC_FORMAT);
	free_tab(vec);
	return (EXIT_FAILURE);
}

int	set_normalized_cy_vect(t_cylinder *cy, char *split)
{
	char	**vec;

	vec = ft_split(split, ',');
	if (has_right_args_nb(vec, 3) == true)
	{
		if (_is_right_vec(vec) == false)
		{
			return (free_tab(vec), EXIT_FAILURE);
		}
		cy->axis_vec.x = ft_atof(vec[0]);
		cy->axis_vec.y = ft_atof(vec[1]);
		cy->axis_vec.z = ft_atof(vec[2]);
		normalized(&cy->axis_vec);
		return (free_tab(vec), EXIT_SUCCESS);
	}
	printf("ERROR: normalized cylinder vec %s\n", VEC_FORMAT);
	free_tab(vec);
	return (EXIT_FAILURE);
}

int	set_normalized_cam_vect(t_camera *cam, char *split)
{
	char	**vec;

	vec = ft_split(split, ',');
	if (has_right_args_nb(vec, 3) == true)
	{
		if (_is_right_vec(vec) == false)
		{
			return (free_tab(vec), EXIT_FAILURE);
		}
		cam->direction.x = ft_atof(vec[0]);
		cam->direction.y = ft_atof(vec[1]);
		cam->direction.z = ft_atof(vec[2]);
		return (free_tab(vec), EXIT_SUCCESS);
	}
	printf("ERROR: normalized Camera vec %s\n", VEC_FORMAT);
	free_tab(vec);
	return (EXIT_FAILURE);
}
