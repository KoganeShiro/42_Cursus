/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_check_glb_lights.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:51:23 by cejin             #+#    #+#             */
/*   Updated: 2024/10/21 14:12:58 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

/*
* split[0] = identifyer (L)
* split[1] = pos (x,y,z)
* split[2] = brightness ratio
*/

//light brightness ratio in range [-1;1]
static int	_fill_light_value(t_graphics *rt, char **split)
{
	if (set_position(rt, LIGHT, split[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (is_right_value(split[2], false, false, false) == false)
	{
		printf("ERROR: Light ratio should be a float\n");
		return (EXIT_FAILURE);
	}
	rt->light->brightness_ratio = ft_atof(split[2]);
	return (EXIT_SUCCESS);
}

int	fill_light(char *line, t_graphics *rt)
{
	char	**split;

	split = ft_split(line, ' ');
	if (has_right_args_nb(split, 3) == true)
	{
		if (_fill_light_value(rt, split) == EXIT_FAILURE)
		{
			return (free_tab(split), EXIT_FAILURE);
		}
		if (light_ratio_check(rt, LIGHT) == true)
		{
			rt->has_require_obj += 1;
			return (free_tab(split), EXIT_SUCCESS);
		}
		else
			return (free_tab(split), EXIT_FAILURE);
	}
	printf("ERROR: Light need 3 %s\n", ERR_WRONG_NB_ARG);
	return (free_tab(split), EXIT_FAILURE);
}

/*
* split[0] = identifyer (A)
* split[1] = lighting ratio
* split[3] = RGB
*/

// ambient lighting ratio in range [-1;1]
// RGB should be in range [0-255] for R, G and B

static int	_check_ambient(t_graphics *rt)
{
	if (light_ratio_check(rt, AMBIENT) == false)
	{
		return (EXIT_FAILURE);
	}
	if (in_range(rt->ambient->color) == false)
	{
		printf("ERROR: Ambient RGB ratio [0;255]\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	_fill_ambient_value(t_graphics *rt, char **split)
{
	if (is_right_value(split[1], false, false, false) == false)
	{
		printf("ERROR: Ambient ratio should be a float\n");
		return (EXIT_FAILURE);
	}
	rt->ambient->lightness_ratio = ft_atof(split[1]);
	if (set_amb_rgb(rt->ambient, split[2]) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	fill_ambient(char *line, t_graphics *rt)
{
	char	**split;

	split = ft_split(line, ' ');
	if (has_right_args_nb(split, 3) == true)
	{
		if (_fill_ambient_value(rt, split) == EXIT_FAILURE)
		{
			return (free_tab(split), EXIT_FAILURE);
		}
		if (_check_ambient(rt) == EXIT_SUCCESS)
		{
			rt->has_require_obj += 1;
			return (free_tab(split), EXIT_SUCCESS);
		}
		else
			return (free_tab(split), EXIT_FAILURE);
	}
	printf("ERROR: Ambient need 3 %s\n", ERR_WRONG_NB_ARG);
	return (free_tab(split), EXIT_FAILURE);
}
