/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:50:17 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 17:53:56 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//The tail become the head in the stack A
void	rra(t_stack_node **a, t_stack_node **cheapest, int check)
{
	(*a) = (*a)->prev;
	(*cheapest)->cost--;
	if (check == 0)
		write(1, "rra\n", 4);
}

//Same but in stack B
void	rrb(t_stack_node **b, t_stack_node **cheapest, int check)
{
	(*b) = (*b)->prev;
	(*cheapest)->cost--;
	if (check == 0)
		write(1, "rrb\n", 4);
}

//Do rra() and rrb()
void	rrr(t_stack_node **a, t_stack_node **b, t_stack_node **cheapest,
				int check)
{
	if (stack_len(a) > 1 && stack_len(b) > 1)
	{
		(*a) = (*a)->prev;
		(*b) = (*b)->prev;
		(*cheapest)->target_node->cost--;
		(*cheapest)->cost--;
	}
	else
		return ;
	if (check == 0)
		write(1, "rrr\n", 4);
}
