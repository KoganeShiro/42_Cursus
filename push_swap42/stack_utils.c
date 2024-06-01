/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:55:23 by cejin             #+#    #+#             */
/*   Updated: 2024/01/29 13:58:37 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node **stack)
{
	int				i;
	t_stack_node	*cur;

	i = 0;
	cur = *stack;
	if (stack == NULL || (*stack) == NULL)
		return (0);
	while (1)
	{
		i++;
		cur = cur->next;
		if (cur == (*stack))
			break ;
	}
	return (i);
}

int	is_stack_sorted(t_stack_node *head)
{
	t_stack_node	*cur;

	if (head == NULL)
		return (1);
	cur = head;
	if (cur->element > cur->next->element)
		return (0);
	cur = cur->next;
	while (cur != head)
	{
		if (cur->next == head)
			break ;
		if (cur->element > cur->next->element)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (ft_strlen((const char *)s1) > 4)
		return (-1);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
