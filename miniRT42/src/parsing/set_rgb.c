/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:18:40 by cejin             #+#    #+#             */
/*   Updated: 2024/10/21 11:43:48 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

static int	_is_right_rgb(char **rgb)
{
	if (is_right_value(rgb[0], false, false, false) == false)
	{
		printf("ERROR (r [0;255)\n");
		return (false);
	}
	if (is_right_value(rgb[1], false, false, false) == false)
	{
		printf("ERROR (g [0;255)\n");
		return (false);
	}
	if (is_right_value(rgb[2], false, false, false) == false)
	{
		printf("ERROR (b [0;255])\n");
		return (false);
	}
	return (true);
}

int	set_sp_rgb(t_sphere *sp, char *split)
{
	char	**rgb;

	rgb = ft_split(split, ',');
	if (has_right_args_nb(rgb, 3) == true)
	{
		if (_is_right_rgb(rgb) == false)
		{
			return (free(rgb), EXIT_FAILURE);
		}
		sp->color.r = ft_atof(rgb[0]);
		sp->color.g = ft_atof(rgb[1]);
		sp->color.b = ft_atof(rgb[2]);
		free_tab(rgb);
		return (EXIT_SUCCESS);
	}
	free_tab(rgb);
	printf("ERROR: sphere %s\n", RGB_FORMAT);
	return (EXIT_FAILURE);
}

int	set_pl_rgb(t_plane *pl, char *split)
{
	char	**rgb;

	rgb = ft_split(split, ',');
	if (has_right_args_nb(rgb, 3) == true)
	{
		if (_is_right_rgb(rgb) == false)
		{
			return (free(rgb), EXIT_FAILURE);
		}
		pl->color.r = ft_atof(rgb[0]);
		pl->color.g = ft_atof(rgb[1]);
		pl->color.b = ft_atof(rgb[2]);
		free_tab(rgb);
		return (EXIT_SUCCESS);
	}
	free_tab(rgb);
	printf("ERROR: plane %s\n", RGB_FORMAT);
	return (EXIT_FAILURE);
}

int	set_cy_rgb(t_cylinder *cy, char *split)
{
	char	**rgb;

	rgb = ft_split(split, ',');
	if (has_right_args_nb(rgb, 3) == true)
	{
		if (_is_right_rgb(rgb) == false)
		{
			return (free(rgb), EXIT_FAILURE);
		}
		cy->color.r = ft_atof(rgb[0]);
		cy->color.g = ft_atof(rgb[1]);
		cy->color.b = ft_atof(rgb[2]);
		free_tab(rgb);
		return (EXIT_SUCCESS);
	}
	free_tab(rgb);
	printf("ERROR: cylinder %s\n", RGB_FORMAT);
	return (EXIT_FAILURE);
}

int	set_amb_rgb(t_ambient *amb, char *split)
{
	char	**rgb;

	rgb = ft_split(split, ',');
	if (has_right_args_nb(rgb, 3) == true)
	{
		if (_is_right_rgb(rgb) == false)
		{
			return (free(rgb), EXIT_FAILURE);
		}
		amb->color.r = ft_atof(rgb[0]);
		amb->color.g = ft_atof(rgb[1]);
		amb->color.b = ft_atof(rgb[2]);
		free_tab(rgb);
		return (EXIT_SUCCESS);
	}
	free_tab(rgb);
	printf("ERROR: Ambient %s\n", RGB_FORMAT);
	return (EXIT_FAILURE);
}
