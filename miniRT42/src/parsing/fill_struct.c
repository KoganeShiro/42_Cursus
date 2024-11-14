/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:43:05 by cejin             #+#    #+#             */
/*   Updated: 2024/10/25 18:51:51 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

static int	_fill_obj(char *line, int i, t_graphics *rt)
{
	if (line[i] == 's' && line[i + 1] == 'p'
		&& is_whitespaces(line[i + 2]) == true)
	{
		if (fill_sphere(line, add_end_node(
					rt, &rt->lst_obj, SPHERE)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (line[i] == 'p' && line[i + 1] == 'l'
		&& is_whitespaces(line[i + 2]) == true)
	{
		if (fill_plane(line, add_end_node(
					rt, &rt->lst_obj, PLANE)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (line[i] == 'c' && line[i + 1] == 'y'
		&& is_whitespaces(line[i + 2]) == true)
	{
		if (fill_cylinder(line, add_end_node(
					rt, &rt->lst_obj, CYLINDER)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
		return (NOT_THE_OBJ);
	printf("fill geometrical obj with success !\n");
	return (EXIT_SUCCESS);
}

static int	_fill_camera(char *line, int i, t_graphics *rt)
{
	static bool	got_camera = false;

	if (line[i] == 'C' && is_whitespaces(line[i + 1]) == true)
	{
		if (fill_camera(line, rt) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (got_camera == true)
		{
			rt->has_require_obj = OBJ_DOUBLE;
		}
		got_camera = true;
		printf("fill camera with success\n");
		return (EXIT_SUCCESS);
	}
	return (NOT_THE_OBJ);
}

static int	_fill_glb_lights(char *line, int i, t_graphics *rt)
{
	static bool	got_light = false;
	static bool	got_ambient = false;

	if (line[i] == 'L' && is_whitespaces(line[i + 1]) == true)
	{
		if (fill_light(line, rt) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (got_light == true)
			rt->has_require_obj = OBJ_DOUBLE;
		got_light = true;
		printf("fill light with success\n");
		return (EXIT_SUCCESS);
	}
	else if (line[i] == 'A' && is_whitespaces(line[i + 1]) == true)
	{
		if (fill_ambient(line, rt) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (got_ambient == true)
			rt->has_require_obj = OBJ_DOUBLE;
		got_ambient = true;
		printf("fill ambient with success\n");
		return (EXIT_SUCCESS);
	}
	return (NOT_THE_OBJ);
}

static int	_returning(int (*func)(char *, int, t_graphics *),
		char *line, int i, t_graphics *rt)
{
	int	exit_with;

	exit_with = func(line, i, rt);
	if (exit_with == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else if (exit_with == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (NOT_THE_OBJ);
}

int	fill_struct(char *line, int i, t_graphics *rt)
{
	int	exit_with;

	if (line == NULL || line[0] == '\0' || line[0] == '\n')
		return (-1);
	exit_with = _returning(_fill_camera, line, i, rt);
	if (exit_with != NOT_THE_OBJ)
		return (exit_with);
	exit_with = _returning(_fill_glb_lights, line, i, rt);
	if (exit_with != NOT_THE_OBJ)
		return (exit_with);
	exit_with = _returning(_fill_obj, line, i, rt);
	if (exit_with != NOT_THE_OBJ)
		return (exit_with);
	if (line[i] == '#')
		return (EXIT_SUCCESS);
	printf("%s\n", UNKNOWN_OBJ);
	return (EXIT_FAILURE);
}
