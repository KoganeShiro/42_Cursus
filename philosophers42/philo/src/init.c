/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:22:43 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 18:33:39 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	initialisation(t_program *prog)
{
	int		i;

	i = 0;
	prog->stop = 0;
	prog->philo_finish_meal = 0;
	prog->philo_tab = malloc(prog->nb_of_philo * sizeof(t_philo *));
	prog->forks = malloc(prog->nb_of_philo * sizeof(pthread_mutex_t));
	if (!prog->philo_tab || !prog->forks)
	{
		ft_putstr_fd("Malloc Error", 2, prog);
		return ;
	}
	while (i < prog->nb_of_philo)
	{
		if (init_philo(prog, i) == -1)
			return ;
		pthread_mutex_init(&(prog->forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(prog->write_lock), NULL);
	pthread_mutex_init(&(prog->ending), NULL);
	distrib_forks(prog);
}

int	init_philo(t_program *prog, int i)
{
	prog->philo_tab[i] = malloc(sizeof(t_philo));
	if (!prog->philo_tab[i])
	{
		free(prog->philo_tab);
		free(prog->forks);
		ft_putstr_fd("Malloc Error", 2, prog);
		return (-1);
	}
	prog->philo_tab[i]->prog = prog;
	prog->philo_tab[i]->id = i + 1;
	prog->philo_tab[i]->meal_count = 0;
	prog->philo_tab[i]->last_meal_time = 0;
	prog->philo_tab[i]->finish_all_meal = 0;
	prog->philo_tab[i]->death_flag = false;
	pthread_mutex_init(&(prog->philo_tab[i]->meal), NULL);
	return (0);
}

void	distrib_forks(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_of_philo - 1)
	{
		prog->philo_tab[i]->right_fork = &(prog->forks[i]);
		prog->philo_tab[i]->left_fork = &(prog->forks[i + 1]);
		i++;
	}
	prog->philo_tab[i]->right_fork = &(prog->forks[i]);
	prog->philo_tab[i]->left_fork = &(prog->forks[0]);
}

void	init_thread(t_program *prog)
{
	pthread_t	guardian_thread;
	int			i;

	prog->start_time = ft_get_cur_time();
	if (prog->nb_of_philo == 1)
	{
		ft_one_philo(prog);
		return ;
	}
	i = 0;
	while (i < prog->nb_of_philo)
	{
		pthread_create(&prog->philo_tab[i]->thread, NULL,
			philo_routine, prog->philo_tab[i]);
		i++;
	}
	i = -1;
	pthread_create(&guardian_thread, NULL,
		ft_guardian, prog);
	pthread_join(guardian_thread, NULL);
	while (++i < prog->nb_of_philo)
		pthread_join(prog->philo_tab[i]->thread, NULL);
}
