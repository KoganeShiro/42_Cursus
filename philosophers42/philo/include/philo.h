/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:10:23 by cejin             #+#    #+#             */
/*   Updated: 2024/05/28 12:12:36 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>

# define MSG "Usage:\n\
./philo nb_of_philo, time_to_die, eating_time, \
sleeping_time, (nb_of_times_each_philo_must_eat)"

/* COLORS */
# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLLOW	"\x1B[33m"
# define BLUE		"\x1B[34m"
# define RESET		"\x1B[0m"

typedef struct s_philo	t_philo;

enum e_action
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
	LEFT_FORK,
	RIGHT_FORK
};

typedef struct s_program
{
	int				nb_of_philo; //== nb_of_fork
	size_t			time_to_die; //time philo will die if they don't eat
	size_t			eating_time; //time philo take to eat
	size_t			sleeping_time; //time philo take to sleep
	int				meals_to_eat; //faculatif arg
	size_t			start_time;
	int				error;
	int				philo_finish_meal;
	bool			stop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	ending;
	t_philo			**philo_tab;
}	t_program;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meal_count;
	bool			finish_all_meal;
	bool			death_flag;
	size_t			last_meal_time;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	meal;
	t_program		*prog;

}	t_philo;

/* MAIN */
//void	ft_display_msg(char *action, t_philo *philo);
void	ft_display_msg(enum e_action action, t_philo *philo);
int		init_value(t_program *prog, char **arg);
bool	check_arg(char **argv);
int		main(int argc, char **argv);

/* INIT */
void	initialisation(t_program *prog);
int		init_philo(t_program *prog, int i);
void	distrib_forks(t_program *prog);
void	init_thread(t_program *prog);

/* PHILO */
void	ft_one_philo(t_program *prog);
bool	is_it_finish(t_philo *philo);
void	*philo_routine(void *arg);
int		ft_eat(t_philo *philo);

/* MONITOR */
void	*ft_guardian(void *arg);
bool	get_count_meals(t_program *prog);
bool	ft_death(t_program *prog);

/* TIME */
void	ft_sleep(t_philo *philo, size_t time);
int		ft_usleep(size_t milliseconds);
size_t	ft_get_cur_time(void);

/* UTILS */
bool	ft_isdigit(char *arg);
int		ft_atoui(char *number);
void	ft_putstr_fd(char *s, int fd, t_program *prog);
int		ft_strcmp(char *s1, char *s2);
void	ft_cleanup(t_program *prog);

#endif
