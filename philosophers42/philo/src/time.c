/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:53:52 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 18:33:24 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_sleep(t_philo *philo, size_t time)
{
	ft_display_msg(SLEEPING, philo);
	ft_usleep(time);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = ft_get_cur_time();
	while ((ft_get_cur_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

size_t	ft_get_cur_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
