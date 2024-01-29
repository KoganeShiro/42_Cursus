/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:50:23 by cejin             #+#    #+#             */
/*   Updated: 2024/01/23 15:08:15 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*delete_on_top(t_stack_node **a)
{
	t_stack_node	*del_top;

	if ((*a) == NULL || a == NULL)
		return (NULL);
	del_top = *a;
	if (*a && (*a)->next->element != (*a)->element)
	{
		(*a)-> next -> prev = (*a)-> prev;
		(*a)-> prev -> next = (*a)-> next;
		*a = (*a)-> next;
	}
	else if (*a)
		*a = NULL;
	return (del_top);
}

void	append_on_top(t_stack_node **from, t_stack_node **dest)
{
	t_stack_node	*head;

	if ((*from) == NULL || from == NULL)
		return ;
	head = delete_on_top(from);
	if ((*dest) == NULL)
	{
		head->next = head;
		head->prev = head;
	}
	else
	{
		head->next = (*dest);
		head->prev = (*dest)->prev;
		(*dest)->prev->next = head;
		(*dest)->prev = head;
	}
	(*dest) = head;
}

//head of stack B, move to head of stack A
//if stack B == NULL; do nothing
void	pa(t_stack_node **b, t_stack_node **a, int check)
{
	if ((*b) != NULL)
	{
		append_on_top(b, a);
		if (check == 0)
			write(1, "pa\n", 3);
	}
}

//head of stack A, move to head of stack B
//if stack A == NULL; do nothing
void	pb(t_stack_node **a, t_stack_node **b, int check)
{
	if ((*a) != NULL)
	{
		append_on_top(a, b);
		if (check == 0)
			write(1, "pb\n", 3);
	}
}
