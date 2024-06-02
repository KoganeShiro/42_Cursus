/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:19:38 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 18:07:35 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				total_words;
	int				i;
	int				success;

	i = -1;
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	else
	{
		total_words = total_element(argv, argc);
		argv = tab_arg(argv, argc, total_words);
	}
	success = init_stack_a(&a, argv);
	if (success == -42)
		return (ft_free(argv), free_node(&a), free_node(&b));
	if (is_stack_sorted(a) == 1)
		return (ft_free(argv), free_node(&a));
	else if (is_stack_sorted(a) == 0)
		ft_sorting(&a, &b, total_words);
	return (ft_free(argv), free_node(&a), free_node(&b));
}
