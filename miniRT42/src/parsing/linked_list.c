/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:40:21 by cejin             #+#    #+#             */
/*   Updated: 2024/10/25 18:51:26 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

t_geo_obj	*add_end_node(t_graphics *rt, t_geo_obj **head,
				t_objects_type type)
{
	t_geo_obj	*current;

	if ((*head) == NULL)
	{
		(*head) = create_new_node(type);
		rt->nearest_obj->obj = (*head);
		if ((*head) == NULL)
			return (NULL);
		else
			return (*head);
	}
	current = (*head);
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = create_new_node(type);
	if (current->next == NULL)
		return (NULL);
	return (current->next);
}

static t_geo_obj	*_malloc_node(t_geo_obj *node, t_objects_type type)
{
	node = (t_geo_obj *)ft_calloc(1, sizeof(t_geo_obj));
	if (node == NULL)
		return (NULL);
	node->type = type;
	return (node);
}

t_geo_obj	*create_new_node(t_objects_type type)
{
	t_geo_obj	*node;

	node = _malloc_node(NULL, type);
	if (node == NULL)
		return (NULL);
	if (type == SPHERE)
	{
		node->sphere = ft_calloc(1, sizeof(t_sphere));
		if (node->sphere == NULL)
			return (NULL);
	}
	else if (type == PLANE)
	{
		node->plane = ft_calloc(1, sizeof(t_plane));
		if (node->plane == NULL)
			return (NULL);
	}
	else if (type == CYLINDER)
	{
		node->cylinder = ft_calloc(1, sizeof(t_cylinder));
		if (node->cylinder == NULL)
			return (NULL);
	}
	node->next = NULL;
	return (node);
}
