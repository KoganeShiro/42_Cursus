/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:36:16 by cejin             #+#    #+#             */
/*   Updated: 2024/01/06 16:33:10 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_error_and_free(t_stack_node **a)
{
	write(2, "Error\n", 6);
	if (a != NULL || (*a) != NULL)
	{
		free_node(a);
		(*a) = NULL;
	}
	return (-42);
}

int	free_node(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*node;
	t_stack_node	*next;

	if (stack == NULL || (*stack) == NULL)
		return (0);
	head = (*stack);
	node = (*stack);
	while (1)
	{
		next = node->next;
		free(node);
		node = next;
		if (node == head)
			break ;
	}
	(*stack) = NULL;
	return (-42);
}

int	ft_free(char **split_result)
{
	int	i;

	i = 0;
	if (split_result == NULL)
		return (0);
	while (split_result[i] != NULL)
	{
		free(split_result[i]);
		i++;
	}
	free(split_result);
	return (-42);
}

long	ft_atol(char *av)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (av[i] == '-' || av[i] == '+')
	{
		if (av[i] == '-')
			sign = -1;
		i++;
	}
	if (av[i] == '-' || av[i] == '+')
		return (2147483648);
	while (av[i] == '0')
		i++;
	if (ft_strlen(av + i) > 12)
		return (2147483648);
	while (av[i] >= '0' && av[i] <= '9')
		res = res * 10 + av[i++] - '0';
	return (res * sign);
}
