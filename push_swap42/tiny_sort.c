/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:31:21 by cejin             #+#    #+#             */
/*   Updated: 2024/01/23 15:09:48 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*tiny_sort for three element
! max number on bottom */
void	sort_for_three(t_stack_node **stack)
{
	t_stack_node	*max;

	max = find_max(stack);
	if ((*stack) == max)
		ra(stack, stack, 0);
	else if ((*stack)->next == max)
		rra(stack, stack, 0);
	if ((*stack)->element > (*stack)->next->element)
		sa(*stack, 0);
}

void	mini_algo(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min;

	min = find_min(a);
	if (min->element != (*a)->element)
		min_on_top(a, min);
	pb(a, b, 0);
	min = find_min(a);
	if (min->element != (*a)->element)
		min_on_top(a, min);
	pb(a, b, 0);
	sort_for_three(a);
	pa(b, a, 0);
	pa(b, a, 0);
}

t_stack_node	*find_max(t_stack_node **stack)
{
	t_stack_node	*max;
	t_stack_node	*cur;

	max = *stack;
	cur = (*stack)->next;
	while (cur->element != (*stack)->element)
	{
		if (cur->element > max->element)
			max = cur;
		cur = cur->next;
	}
	return (max);
}

t_stack_node	*find_min(t_stack_node **stack)
{
	t_stack_node	*min;
	t_stack_node	*cur;

	min = *stack;
	cur = (*stack)->next;
	while (cur->element != (*stack)->element)
	{
		if (cur->element < min->element)
			min = cur;
		cur = cur->next;
	}
	return (min);
}
