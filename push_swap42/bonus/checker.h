/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:49:27 by cejin             #+#    #+#             */
/*   Updated: 2024/01/29 14:15:40 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

//t_stack_node	*init_check_stack(t_stack_node **a, char **av);
int		init_check_stack(t_stack_node **a, char **av);
int		check_instructions(t_stack_node **a, t_stack_node **b,
			char *input);
void	reset_str(char **str);
void	check_is_sorted(t_stack_node *a);
int		main(int argc, char **argv);

#endif
