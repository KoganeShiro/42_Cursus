/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:50:10 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 17:53:46 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//The head become the tail in the stack A
void	ra(t_stack_node **a, t_stack_node **cheapest, int check)
{
	(*a) = (*a)->next;
	(*cheapest)->cost--;
	if (check == 0)
		write(1, "ra\n", 3);
}

//Same but in stack B
void	rb(t_stack_node **b, t_stack_node **cheapest, int check)
{
	(*b) = (*b)->next;
	(*cheapest)->cost--;
	if (check == 0)
		write(1, "rb\n", 3);
}

//Do ra() and rb()
void	rr(t_stack_node **a, t_stack_node **b, t_stack_node **cheapest,
				int check)
{
	if (stack_len(a) > 1 && stack_len(b) > 1)
	{
		(*a) = (*a)->next;
		(*b) = (*b)->next;
		(*cheapest)->target_node->cost--;
		(*cheapest)->cost--;
	}
	else
		return ;
	if (check == 0)
		write(1, "rr\n", 3);
}
