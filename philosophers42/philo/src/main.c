/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:19:35 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 18:33:34 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

#define NOT_INTEGER "Only integers are allowed (no '-' or '+')"

#define NB_OF_PHILO_ERR "200 philo is the max \
but one program is necessary"

bool	check_arg(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_isdigit(argv[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

void	_init_meal_count(t_program *prog, char **arg)
{
	if (arg[5] != NULL)
	{
		if (ft_atoui(arg[5]) >= 1)
			prog->meals_to_eat = ft_atoui(arg[5]);
		else
			ft_putstr_fd("no meals_count\nEnding...", 2, prog);
	}
	else if (arg[5] == NULL)
		prog->meals_to_eat = -1;
}

int	init_value(t_program *prog, char **arg)
{
	if (ft_atoui(arg[1]) <= 200 && ft_atoui(arg[1]) != 0)
		prog->nb_of_philo = ft_atoui(arg[1]);
	else
		ft_putstr_fd(NB_OF_PHILO_ERR, 2, prog);
	if (ft_atoui(arg[2]) >= 60)
		prog->time_to_die = ft_atoui(arg[2]);
	else
		ft_putstr_fd("die time: 60ms is the lowest time", 2, prog);
	if (ft_atoui(arg[3]) >= 60)
		prog->eating_time = ft_atoui(arg[3]);
	else
		ft_putstr_fd("eat time: 60ms is the lowest time", 2, prog);
	if (ft_atoui(arg[4]) >= 60)
		prog->sleeping_time = ft_atoui(arg[4]);
	else
		ft_putstr_fd("sleep time: 60ms is the lowest time", 2, prog);
	_init_meal_count(prog, arg);
	return (prog->error);
}

/* uncomment this if it doesn't work well
void	ft_display_msg(enum e_action action, t_philo *philo)
{
	int	time;

	if (is_it_finish(philo))
		return ;
	pthread_mutex_lock(&(philo->prog->write_lock));
	time = ft_get_cur_time() - philo->prog->start_time;
	if (action == LEFT_FORK)
		printf("%d %d has taken a fork\n", time, philo->id);
	else if (action == RIGHT_FORK)
		printf("%d %d has taken a fork\n", time, philo->id);
	else if (action == EATING)
		printf("%d %d is eating\n", time, philo->id);
	else if (action == SLEEPING)
		printf("%d %d is sleeping\n", time, philo->id);
	else if (action == THINKING)
		printf("%d %d is thinking\n", time, philo->id);
	else if (action == DEAD)
		printf("%d %d died\n", time, philo->id);
	pthread_mutex_unlock(&(philo->prog->write_lock));
}
*/

void	ft_display_msg(enum e_action action, t_philo *philo)
{
	if (is_it_finish(philo))
		return ;
	pthread_mutex_lock(&(philo->prog->write_lock));
	printf("%lu", ft_get_cur_time() - philo->prog->start_time);
	if (action == LEFT_FORK)
		printf(" | %d Is taking the left fork\n", philo->id);
	else if (action == RIGHT_FORK)
		printf(" | %d Is taking the right fork\n", philo->id);
	else if (action == EATING)
		printf(" | %d Is eating 🍝 (%d)\n", philo->id, philo->meal_count + 1);
	else if (action == SLEEPING)
		printf(" | %d Is sleeping 🛌💤\n", philo->id);
	else if (action == THINKING)
		printf(" | %d Is thinking 🤔💭\n", philo->id);
	else if (action == DEAD)
		printf(" | %d Is Dead 🪦\n", philo->id);
	pthread_mutex_unlock(&(philo->prog->write_lock));
}


int	main(int argc, char **argv)
{
	t_program	*prog;

	prog = malloc(1 * sizeof(t_program));
	prog->error = 0;
	if (!(argc == 5 || argc == 6))
		ft_putstr_fd(MSG, 2, prog);
	else if (check_arg(argv) == true)
	{
		init_value(prog, argv);
		if (prog->error == 0)
		{
			initialisation(prog);
			init_thread(prog);
			ft_cleanup(prog);
		}
	}
	else
		ft_putstr_fd(NOT_INTEGER, 2, prog);
	free(prog);
	return (0);
}
