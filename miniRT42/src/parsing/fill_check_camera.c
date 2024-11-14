/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_check_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:57:45 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:56:39 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

static bool	_fov_range_check(t_camera *cam)
{
	if (cam->fov >= 0. && cam->fov <= 180.)
		return (true);
	return (false);
}

static int	_check_camera(t_graphics *rt)
{
	if (_fov_range_check(rt->camera) == false)
	{
		printf("FOV not in range ([0;180])\n");
		return (EXIT_FAILURE);
	}
	if (normalized_check(rt->camera->direction) == false)
	{
		printf("Camera vect is not normalize ([-1;1])\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
* split[0] = identifyer (C)
* split[1] = pos (x,y,z)
* split[3] = 3d normalized orientation vec (x,y,z)
* split[4] = FOV (nb in degrees)
*/

static int	_fill_camera_value(t_graphics *rt,
	char **split)
{
	if (set_position(rt, CAMERA, split[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (set_normalized_cam_vect(rt->camera, split[2]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (is_right_value(split[3], false, false, false) == false)
	{
		printf("ERROR: FOV should be a float\n");
		return (EXIT_FAILURE);
	}
	rt->camera->fov = ft_atof(split[3]);
	return (EXIT_SUCCESS);
}

int	fill_camera(char *line, t_graphics *rt)
{
	char	**split;

	split = ft_split(line, ' ');
	if (has_right_args_nb(split, 4) == true)
	{
		if (_fill_camera_value(rt, split) == EXIT_FAILURE)
		{
			return (free_tab(split), EXIT_FAILURE);
		}
		if (_check_camera(rt) == EXIT_SUCCESS)
		{
			rt->has_require_obj += 1;
			return (free_tab(split), EXIT_SUCCESS);
		}
		else
			return (free_tab(split), EXIT_FAILURE);
	}
	printf("ERROR: Camera need 4 %s\n", ERR_WRONG_NB_ARG);
	return (free_tab(split), EXIT_FAILURE);
}
