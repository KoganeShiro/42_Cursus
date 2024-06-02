/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:22:23 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 17:54:03 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	cost_to_top(t_stack_node **a, t_stack_node **target)
{
	t_stack_node	*top;
	t_stack_node	*bottom;
	int				cost;

	cost = 1;
	top = (*target)->next;
	bottom = (*target)->prev;
	while (top->element != (*a)->element && bottom->element != (*a)->element)
	{
		cost++;
		top = top->next;
		bottom = bottom->prev;
	}
	if (top->element == (*a)->element)
		(*target)->is_rotate = -1;
	else
	{
		(*target)->is_rotate = 1;
	}
	(*target)->cost = cost;
}

void	set_cost(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cur;
	t_stack_node	*target;

	(*a)->cost = 0;
	target = set_target(b, (*a)->element);
	(*a)->target_node = target;
	cur = (*a)->next;
	while (cur->element != (*a)->element)
	{
		cost_to_top(a, &cur);
		target = set_target(b, cur->element);
		cur->target_node = target;
		cur = cur->next;
	}
	(*b)->cost = 0;
	cur = (*b)->next;
	while (cur->element != (*b)->element)
	{
		cost_to_top(b, &cur);
		cur = cur->next;
	}
}

int	set_price(t_stack_node *a)
{
	int	price;

	price = 0;
	if (a->is_rotate < 0 == a->target_node->is_rotate < 0)
	{
		if (a->cost >= a->target_node->cost)
			price = a->cost;
		else
			price = a->target_node->cost;
	}
	else
	{
		price = a->cost + a->target_node->cost;
	}
	return (price);
}

t_stack_node	*find_cheapest(t_stack_node *a)
{
	t_stack_node	*cheapest;
	t_stack_node	*current;
	int				min;

	cheapest = a;
	current = a->next;
	min = set_price(a);
	while (current->element != a->element)
	{
		if (min > set_price(current))
		{
			cheapest = current;
			min = set_price(current);
		}
		current = current->next;
	}
	return (cheapest);
}
