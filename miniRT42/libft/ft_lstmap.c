/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:19:45 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/30 18:31:54 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*noeud;

	lst_new = NULL;
	while (lst)
	{
		noeud = ft_lstnew(NULL);
		if (noeud == NULL)
		{
			ft_lstclear(&lst_new, del);
			break ;
		}
		noeud->content = f(lst->content);
		ft_lstadd_back(&lst_new, noeud);
		lst = lst->next;
	}
	return (lst_new);
}
