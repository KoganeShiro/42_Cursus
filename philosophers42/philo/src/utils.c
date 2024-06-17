/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:10:13 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 18:33:19 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	ft_isdigit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

int	ft_atoui(char *number)
{
	unsigned long	res;
	int				i;

	i = 0;
	res = 0;
	if (number == NULL)
		return (-1);
	while (number[i] >= '0' && number[i] <= '9')
	{
		res = res * 10 + (number[i] - '0');
		i++;
	}
	if (res > 2147483647)
		return (0);
	return (res);
}

void	ft_putstr_fd(char *s, int fd, t_program *prog)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
	write(fd, "\n", 1);
	prog->error = 1;
	return ;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_cleanup(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_of_philo)
	{
		pthread_mutex_destroy(&(prog->philo_tab[i]->meal));
		free(prog->philo_tab[i]);
		pthread_mutex_destroy(&(prog->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(prog->write_lock));
	pthread_mutex_destroy(&(prog->ending));
	free(prog->philo_tab);
	free(prog->forks);
}
