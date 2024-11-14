/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:17:33 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/30 18:33:16 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;
	int		last;

	tmp = lst;
	last = ft_lstsize(lst);
	while (last - 1 > 0)
	{
		tmp = tmp->next;
		last--;
	}
	return (tmp);
}
