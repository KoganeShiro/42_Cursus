/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:33:19 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 16:00:53 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_signal_receive = 0;

void	receive_signal(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_printf("Server receive the message ! ⸜(｡ > w 0 )⸝\n");
		g_signal_receive = 1;
	}
	else
		ft_printf("Oh no, it's a faillure... (¬_¬')\n");
}

void	send_to_serv(pid_t pid, char c)
{
	int	byte;
	int	signal;

	byte = 128;
	while (byte != 0)
	{
		if (byte & c)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		if (kill(pid, signal) == -1)
		{
			ft_printf("Error !\n");
			exit(EXIT_FAILURE);
		}
		byte >>= 1;
		usleep(300);
	}
}

/*
void	send_len(pid_t pid, int len)
{
	int	byte;
	int	signal;

	byte = 512;
	ft_printf("send_len len %i\n", len);
	while (byte != 0)
	{
		if (byte & len)
		{
			ft_printf("send_len byte %i\n", byte);
			signal = SIGUSR1;
		}
		else
		{
			ft_printf("send_len byte %i\n", byte);
			signal = SIGUSR2;
		}
		if (kill(pid, signal) == -1)
		{
			ft_printf("Error !\n");
			exit(EXIT_FAILURE);
		}
		byte >>= 1;
		usleep(100);
	}
	usleep(300);
}
*/

void	send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	ft_printf("\nWaiting for the server answer...\n");
	while (str[i] != '\0')
	{
		send_to_serv(pid, str[i]);
		i++;
	}
	send_to_serv(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Please, give a PID and a string only !\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atou(argv[1]);
	sa.sa_handler = &receive_signal;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_str(server_pid, argv[2]);
	while (g_signal_receive == 0)
		pause();
	return (0);
}
