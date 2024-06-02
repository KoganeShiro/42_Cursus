/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:48:03 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 17:52:37 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* NOT GOOD ! DOESN'T WORK
./checker argv

argv = all the element in stack A
if argv = NULL; do nothing

read (input); wait for the user to write the instructions
check if the instructions are correct

do the instructions with the stack
check if the stack is sort
if there is an error output: "Error\n"
if yes output: "OK\n"
else output: "KO\n"
*/

int	init_check_stack(t_stack_node **a, char **av)
{
	int		i;
	long	element;

	i = 1;
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

int	check_instructions(t_stack_node **a, t_stack_node **b, char *input)
{
	if (ft_strcmp(input, "ra\n") == 0)
		ra(a, a, 1);
	else if (ft_strcmp(input, "rb\n") == 0)
		rb(b, a, 1);
	else if (ft_strcmp(input, "rr\n") == 0)
		rr(a, b, a, 1);
	else if (ft_strcmp(input, "rra\n") == 0)
		rra(a, a, 1);
	else if (ft_strcmp(input, "rrb\n") == 0)
		rrb(b, a, 1);
	else if (ft_strcmp(input, "rrr\n") == 0)
		rrr(a, b, a, 1);
	else if (ft_strcmp(input, "pa\n") == 0)
		pa(b, a, 1);
	else if (ft_strcmp(input, "pb\n") == 0)
		pb(a, b, 1);
	else if (ft_strcmp(input, "sa\n") == 0)
		sa(*a, 1);
	else if (ft_strcmp(input, "sb\n") == 0)
		sb(*b, 1);
	else if (ft_strcmp(input, "ss\n") == 0)
		ss(*a, *b, 1);
	else
		return (-1);
	return (0);
}

void	reset_str(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			str[i][j] = '\0';
			j++;
		}
		i++;
	}
}

void	check_is_sorted(t_stack_node *a)
{
	if (is_stack_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*input;

	a = NULL;
	b = NULL;
	(void)argc;
	init_check_stack(&a, argv);
	if (stack_len(&a) == 1)
		write(1, "OK\n", 3);
	else if (stack_len(&a) > 1)
	{
		input = ft_calloc(10000, sizeof(char));
		while (input[0] != '\n')
		{
			reset_str(&input);
			read(0, input, 10000);
			if (input[0] != '\n' && check_instructions(&a, &b, input) != 0)
				write(1, "The Operation is not recognized\n", 32);
		}
		check_is_sorted(a);
		free(input);
		return (free_node(&a), free_node(&b));
	}
	return (0);
}
