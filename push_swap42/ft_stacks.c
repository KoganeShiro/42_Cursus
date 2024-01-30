/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:50:34 by cejin             #+#    #+#             */
/*   Updated: 2024/01/23 15:12:30 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_a(t_stack_node **a, char **av)
{
	int		i;
	long	element;

	i = 0;
	while (av[i] != NULL)
	{
		if (ft_is_alpha(av[i]) == 1)
			return (put_error_and_free(a));
		else if (ft_is_duplicate(av, i) == 1)
			return (put_error_and_free(a));
		element = ft_atol(av[i]);
		if (element <= -2147483649 || element >= 2147483648)
			return (put_error_and_free(a));
		append_node(a, (int)element);
		i++;
	}
	return (0);
}

//circular so the head->prev == tail and tail->next == head
t_stack_node	*find_last_node(t_stack_node *head)
{
	t_stack_node	*last_node;

	if (head == NULL)
		return (head);
	last_node = head;
	while (last_node->next != head)
		last_node = last_node->next;
	return (last_node);
}

//Insertion of a node at the end of the list, (*stack) point to the head
void	append_node(t_stack_node **stack, int element)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	node = ft_calloc(1, sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->element = element;
	node->next = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = node;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	(*stack)->prev = node;
	node->next = *stack;
}

int	total_element(char **arg, int ac)
{
	int	total_words;
	int	i;

	i = 0;
	total_words = 0;
	while (i < ac)
	{
		total_words += word_count(arg[i], ' ');
		i++;
	}
	return (total_words);
}

char	**tab_arg(char **arg, int ac, int total_words)
{
	int		i;
	int		j;
	char	**tab;
	int		tab_index;
	char	**split_result;

	tab = ft_calloc(total_words + 1, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab_index = 0;
	i = 1;
	while (i < ac)
	{
		split_result = ft_split(arg[i], ' ');
		i++;
		j = 0;
		while (split_result[j] != NULL)
		{
			tab[tab_index++] = ft_strdup(split_result[j]);
			j++;
		}
		ft_free(split_result);
	}
	tab[tab_index] = NULL;
	return (tab);
}
