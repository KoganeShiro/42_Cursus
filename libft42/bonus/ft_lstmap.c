/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:38:36 by cejin             #+#    #+#             */
/*   Updated: 2023/10/27 13:58:15 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	void	*content;

	if (!f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_elem = ft_lstnew(content);
		if (!(new_elem))
		{
			del(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}
/*
#include <stdio.h>

void	del(void *p)
{
	printf("del(%s)\n", (char *)p);
}
void	*function(void *p)
{
	printf("func(%s)\n", (char *)p);
	return (p);
}
int main(void)
{
	t_list *root = NULL;
	int	i;

	i = 0;
	while (i < 5)
	{
		ft_lstadd_back(&root, ft_lstnew("test"));
		i++;
	}
	ft_lstmap(root, function, del);
}
*/
