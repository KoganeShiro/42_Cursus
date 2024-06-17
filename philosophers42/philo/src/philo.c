/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:25:46 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 18:33:27 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_one_philo(t_program *prog)
{
	ft_display_msg(LEFT_FORK, prog->philo_tab[0]);
	ft_usleep(prog->time_to_die);
	while (1)
	{
		usleep(10);
		if (ft_death(prog) == 1)
			break ;
	}
}

bool	is_it_finish(t_philo *philo)
{
	bool	ending;

	pthread_mutex_lock(&(philo->prog->ending));
	ending = philo->prog->stop;
	pthread_mutex_unlock(&(philo->prog->ending));
	return (ending);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&(philo->meal));
	philo->last_meal_time = philo->prog->start_time;
	pthread_mutex_unlock(&(philo->meal));
	if (philo->id % 2)
		ft_usleep(1);
	while (!is_it_finish(philo))
	{
		ft_eat(philo);
		usleep(5);
		ft_sleep(philo, philo->prog->sleeping_time);
		usleep(5);
		ft_display_msg(THINKING, philo);
		usleep(5);
	}
	return (philo);
}

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_display_msg(LEFT_FORK, philo);
	pthread_mutex_lock(philo->right_fork);
	ft_display_msg(RIGHT_FORK, philo);
	ft_display_msg(EATING, philo);
	pthread_mutex_lock(&(philo->meal));
	philo->last_meal_time = ft_get_cur_time();
	philo->meal_count++;
	pthread_mutex_unlock(&(philo->meal));
	ft_usleep(philo->prog->eating_time);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}
