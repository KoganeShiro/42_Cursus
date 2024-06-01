/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:50:29 by cejin             #+#    #+#             */
/*   Updated: 2024/01/23 15:25:19 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_actions(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = find_cheapest(*a);
	while (cheapest->is_rotate < 0 == cheapest->target_node->is_rotate < 0
		&& cheapest->cost != 0 && cheapest->target_node->cost != 0)
	{
		if (cheapest->is_rotate == 1)
			rr(a, b, &cheapest, 0);
		if (cheapest->is_rotate == -1)
			rrr(a, b, &cheapest, 0);
	}
	while (cheapest->cost != 0)
	{
		if (cheapest->is_rotate == 1)
			ra(a, &cheapest, 0);
		else
			rra(a, &cheapest, 0);
	}
	while (cheapest->target_node->cost != 0)
	{
		if (cheapest->target_node->is_rotate == 1)
			rb(b, &cheapest->target_node, 0);
		else
			rrb(b, &cheapest->target_node, 0);
	}
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int				len;
	t_stack_node	*cheapest;

	len = stack_len(a);
	pb(a, b, 0);
	pb(a, b, 0);
	while (len > 2)
	{
		set_cost(a, b);
		cheapest = find_cheapest(*a);
		do_actions(a, b);
		len--;
		pb(a, b, 0);
	}
	check_sort(b);
	len = stack_len(b);
	while (len >= 1)
	{
		pa(b, a, 0);
		len--;
	}
}

t_stack_node	*set_target(t_stack_node **a, int b_element)
{
	t_stack_node	*target;
	t_stack_node	*cur;

	target = *a;
	cur = (*a)->next;
	while (cur->element != (*a)->element)
	{
		if ((b_element > cur->element)
			&& ((b_element - target->element) > (b_element - cur->element)
				|| b_element - target->element < 0))
			target = cur;
		cur = cur->next;
	}
	if (target->element > b_element)
		target = find_max(a);
	return (target);
}

void	check_sort(t_stack_node **b)
{
	t_stack_node	*max;

	max = find_max(b);
	cost_to_top(b, &max);
	while ((*b)->element != max->element)
	{
		if (max->is_rotate == 1)
			rb(b, &max, 0);
		else
			rrb(b, &max, 0);
	}
}

void	min_on_top(t_stack_node **a, t_stack_node *min)
{
	cost_to_top(a, &min);
	while (min->cost != 0)
	{
		if (min->is_rotate == 1)
			ra(a, &min, 0);
		else
			rra(a, &min, 0);
	}
}
