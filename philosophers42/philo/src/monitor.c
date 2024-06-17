/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:29:16 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 18:33:31 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_guardian(void *arg)
{
	t_program	*prog;

	prog = (t_program *)arg;
	while (1)
	{
		if (get_count_meals(prog) == 1 || ft_death(prog) == 1)
		{
			pthread_mutex_lock(&(prog->ending));
			prog->stop = 1;
			pthread_mutex_unlock(&(prog->ending));
			usleep(3);
			break ;
		}
	}
	return (prog);
}

bool	get_count_meals(t_program *prog)
{
	int	i;

	i = 0;
	if (prog->meals_to_eat == -1)
		return (0);
	while (i < prog->nb_of_philo)
	{
		pthread_mutex_lock(&(prog->philo_tab[i]->meal));
		if (prog->philo_tab[i]->meal_count
			>= prog->meals_to_eat
			&& !prog->philo_tab[i]->finish_all_meal)
		{
			prog->philo_finish_meal++;
			prog->philo_tab[i]->finish_all_meal = 1;
		}
		pthread_mutex_unlock(&(prog->philo_tab[i]->meal));
		usleep(10);
		i++;
	}
	if (prog->philo_finish_meal == prog->nb_of_philo)
		return (1);
	return (0);
}

bool	ft_death(t_program *prog)
{
	int		i;
	size_t	time;

	i = 0;
	while (i < prog->nb_of_philo)
	{
		pthread_mutex_lock(&(prog->philo_tab[i]->meal));
		time = prog->philo_tab[i]->last_meal_time;
		pthread_mutex_unlock(&(prog->philo_tab[i]->meal));
		if (ft_get_cur_time() - time
			>= (size_t)prog->time_to_die)
		{
			ft_display_msg(DEAD, prog->philo_tab[i]);
			return (1);
		}
		usleep(10);
		i++;
	}
	return (0);
}
