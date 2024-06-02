/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:40:06 by cejin             #+#    #+#             */
/*   Updated: 2024/02/02 16:36:29 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>
# include <signal.h>

# define BUFFER_SIZE 10000

/* CLIENT */
void	receive_signal(int signal);
void	send_to_serv(pid_t pid, char c);
void	send_str(pid_t pid, char *str);

/* SERVER */
void	print_str(pid_t client_pid);
void	handle_signal(int signal, siginfo_t *info, void *ucontext);

/* FT_UTILS */
void	receive_signal(int signal);
int		ft_atou(char *str);
int		ft_strlen(char *mes);
void	*ft_calloc(size_t str_len, size_t size);
char	*ft_strjoin(char *str, int add);

/* FT_PRINTF */

int		ft_printnbr(int n);
int		ft_printchar(const char c);
int		ft_printstr(const char *str);
int		ft_printptr(unsigned long long ptr);
int		ft_printf(const char *format, ...);
int		ft_printunsigned(unsigned int n);
int		printf_format(va_list args, const char format);
int		ft_printhex(unsigned long nb, char *hex);
void	ft_putchar(const char c);

#endif
