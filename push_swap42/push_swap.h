/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:23:16 by cejin             #+#    #+#             */
/*   Updated: 2024/01/29 11:26:08 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

typedef struct s_stack_node
{
	struct s_stack_node	*prev;
	int					element;
	struct s_stack_node	*target_node;
	int					cost;
	int					is_rotate;
	struct s_stack_node	*next;
}	t_stack_node;

/* MAIN */
int				main(int argc, char **argv);
void			ft_sorting(t_stack_node **a, t_stack_node **b, int len);

/* ALGO */
void			do_actions(t_stack_node **a, t_stack_node **b);
void			push_swap(t_stack_node **a, t_stack_node **b);
t_stack_node	*set_target(t_stack_node **a, int b_element);
void			check_sort(t_stack_node **b);
void			min_on_top(t_stack_node **a, t_stack_node *min);

/* FT_COST */
void			cost_to_top(t_stack_node **a, t_stack_node **b);
void			set_cost(t_stack_node **a, t_stack_node **b);
int				set_price(t_stack_node *a);
t_stack_node	*find_cheapest(t_stack_node *a);

/* TINY_SORT */
void			sort_for_three(t_stack_node **stack);
void			mini_algo(t_stack_node **a, t_stack_node **b);
t_stack_node	*find_max(t_stack_node **stack);
t_stack_node	*find_min(t_stack_node **stack);

/* STACKS */
int				init_stack_a(t_stack_node **a, char **av);
t_stack_node	*find_last_node(t_stack_node *cur);
void			append_node(t_stack_node **stack, int element);
int				total_element(char **arg, int ac);
char			**tab_arg(char **arg, int ac, int total_words);

/* STACK UTILS */
int				is_stack_sorted(t_stack_node *head);
int				stack_len(t_stack_node **stack);
int				ft_strcmp(char *s1, char *s2);

/* FT_PUSH */
t_stack_node	*delete_on_top(t_stack_node **stack);
void			append_on_top(t_stack_node **from, t_stack_node **dest);
void			pa(t_stack_node **b, t_stack_node **a, int check);
void			pb(t_stack_node **a, t_stack_node **b, int check);

/* FT_REVERSE */
void			rra(t_stack_node **a, t_stack_node **cheapest, int check);
void			rrb(t_stack_node **b, t_stack_node **cheapest, int check);
void			rrr(t_stack_node **a, t_stack_node **b,
					t_stack_node **cheapest, int check);
t_stack_node	*find_cheapest(t_stack_node *a);

/* FT_ROTATE */
void			ra(t_stack_node **a, t_stack_node **cheapest, int check);
void			rb(t_stack_node **b, t_stack_node **cheapest, int check);
void			rr(t_stack_node **a, t_stack_node **b,
					t_stack_node **cheapest, int check);

/* FT_SWAP */
void			swap(t_stack_node *a);
void			sa(t_stack_node *a, int check);
void			sb(t_stack_node *b, int check);
void			ss(t_stack_node *a, t_stack_node *b, int check);

/* ERROR_HANDLING */
int				put_error_and_free(t_stack_node **a);
int				free_node(t_stack_node **stack);
int				ft_free(char **split_result);
long			ft_atol(char *av);

/* UTILS */
char			*remove_zero(char *av);
int				ft_is_duplicate(char **av, int index);
int				ft_is_alpha(char *av);
int				ft_strlen(const char *str);
void			*ft_calloc(size_t str_len, size_t size);

/* FT_SPLIT */
char			*ft_strdup(char *str);
int				word_count(char const *s, char space);
char			*next_word(char const *str, int start, int end);
void			fill_result(char **result, const char *s, char space);
char			**ft_split(char const *s, char space);

#endif
