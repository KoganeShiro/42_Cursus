/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:50:04 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 17:53:36 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//swap the top 2 elements of the stack a or b
void	swap(t_stack_node *a)
{
	t_stack_node	*head;
	t_stack_node	tmp;

	if (a == NULL || a->next == a)
		return ;
	head = a;
	a = a->next;
	tmp = *head;
	head->element = a->element;
	a->element = tmp.element;
}

void	sa(t_stack_node *a, int check)
{
	swap(a);
	if (check == 0)
		write(1, "sa\n", 3);
}

//Same but in stack B
void	sb(t_stack_node *b, int check)
{
	swap(b);
	if (check == 0)
		write(1, "sb\n", 3);
}

//Do sa() and sb()
void	ss(t_stack_node *a, t_stack_node *b, int check)
{
	swap(a);
	swap(b);
	if (check == 0)
		write(1, "sd\n", 3);
}
