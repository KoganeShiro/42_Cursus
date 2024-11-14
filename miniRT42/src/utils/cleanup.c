/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:39:08 by cejin             #+#    #+#             */
/*   Updated: 2024/11/12 16:39:13 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	_free_node(t_geo_obj *lst_obj)
{
	if (lst_obj->type == SPHERE)
	{
		free(lst_obj->sphere);
	}
	else if (lst_obj->type == PLANE)
		free(lst_obj->plane);
	else if (lst_obj->type == CYLINDER)
		free(lst_obj->cylinder);
}

static void	_free_lst_obj(t_geo_obj *lst_obj)
{
	t_geo_obj	*tmp;

	tmp = NULL;
	if (lst_obj == NULL)
		return ;
	while (lst_obj != NULL)
	{
		tmp = lst_obj->next;
		_free_node(lst_obj);
		free(lst_obj);
		lst_obj = tmp;
	}
	free(lst_obj);
}

int	cleanup(t_graphics *rt)
{
	free(rt->viewport);
	free(rt->ray);
	free(rt->camera);
	free(rt->ambient);
	free(rt->light);
	_free_lst_obj(rt->lst_obj);
	free(rt->nearest_obj);
	return (EXIT_FAILURE);
}
