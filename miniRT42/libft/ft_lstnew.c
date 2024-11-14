/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:00:16 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/30 13:21:16 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*noeud;

	noeud = malloc(sizeof(t_list));
	if (!noeud)
		return (NULL);
	noeud->content = content;
	noeud->next = NULL;
	return (noeud);
}
