/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:33:46 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 16:00:01 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/*
void	alloc_len(int signal)
{
	int				len;
	static int		byte = 0;
	static int		count = 0;

	len = 0;
	if (signal == SIGUSR1)
		byte = (byte << 1) | 1;
	else
		byte = byte << 1;
	count++;
	if (count == 32)
		len = byte;
	ft_printf("alloc_len len %i\n", len);
	g_mes = ft_calloc(len + 1, sizeof(char));
		if (g_mes == NULL)
			exit(EXIT_FAILURE);
	count = 0;
}

void	print_str(int add, pid_t client_pid)
{
	static char		mes[BUFFER_SIZE];
	static int		i = 0;

	if (add != '\0')
	{
		mes[i] = add;
		i++;
	}
	else
	{
		mes[i] = add;
		ft_printf("\n\nFrom %i:\n%s", client_pid, mes);
		i = 0;
	}
}
*/

char	*mes = NULL;

void	print_str(pid_t client_pid)
{
	int		i;

	i = 0;
	ft_printf("From %i\n", client_pid);
	while (mes != NULL && mes[i] != '\0')
	{
		write(1, &mes[i], 1);
		i++;
	}
	mes = NULL;
	return ;
}

//Use binary because we can only use SIGUSR1 and SIGUSR2 as signals
//recustruct the string with the bit that the client send
void	handle_signal(int signal, siginfo_t *info, void *ucontext)
{
	static int		byte = 0;
	static int		count = 0;
	static pid_t	client_pid = 0;

	(void)ucontext;
	client_pid = info->si_pid;
	byte = byte << 1;
	if (signal == SIGUSR1)
		byte = byte | 1;
	count++;
	if (count == 8)
	{
		if (byte == '\0')
		{
			print_str(client_pid);
			kill(client_pid, SIGUSR2);
		}
		mes = ft_strjoin(mes, byte);
		count = 0;
		byte = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
