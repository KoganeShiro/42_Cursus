/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:31:12 by cejin             #+#    #+#             */
/*   Updated: 2023/10/25 19:22:04 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t_lst;

	t_lst = malloc(sizeof(t_list) * 1);
	if (t_lst == NULL)
		return (NULL);
	t_lst -> content = content;
	t_lst -> next = NULL;
	return (t_lst);
}
