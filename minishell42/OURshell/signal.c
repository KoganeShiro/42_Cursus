/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:17:14 by vharatyk          #+#    #+#             */
/*   Updated: 2024/06/20 16:49:38 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_sig;

void	check_exitcode(t_shell *shell)
{
	if (g_sig)
	{
		shell->exit_code = 128 + g_sig;
		g_sig = 0;
	}
}

static void	sig_handle_rl(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		g_sig = SIGINT;
	}
}

static void	sig_handle_exec(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd(2, "Quit (core dumped)\n");
		g_sig = SIGQUIT;
	}
	else if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		g_sig = SIGINT;
	}
}

static void	sig_handle_heredoc(int sig)
{
	if (sig == SIGQUIT)
		write(1, "\b\b  \b\b", 6);
	else if (sig == SIGINT)
	{
		write(1, "\n", 1);
		g_sig = SIGINT;
	}
}

void	get_signal(int state)
{
	struct sigaction	s_int;
	struct sigaction	s_quit;

	sigemptyset(&(s_int.sa_mask));
	sigemptyset(&(s_quit.sa_mask));
	s_int.sa_flags = SA_RESTART;
	s_quit.sa_flags = SA_RESTART;
	if (state == 0)
	{
		s_int.sa_handler = sig_handle_rl;
		s_quit.sa_handler = SIG_IGN;
	}
	else if (state == 1)
	{
		s_int.sa_handler = sig_handle_exec;
		s_quit.sa_handler = sig_handle_exec;
	}
	else if (state == 2)
	{
		s_int.sa_handler = sig_handle_heredoc;
		s_quit.sa_handler = sig_handle_heredoc;
		s_int.sa_flags = 0;
	}
	sigaction(SIGQUIT, &s_quit, NULL);
	sigaction(SIGINT, &s_int, NULL);
}

/*
void	signals(t_shell *shell)
{
	g_ctrl_c = false;
	//save_settings_and_remove_c(shell); pk ??
	signal_ctrl_backslash();
	signal_ctrl_c();
}

// void	save_settings_and_remove_c(t_shell *shell)
// {
// 	t_shell		shell;

// 	tcgetattr(1, mirror_termios);
// 	tcgetattr(1, &termios_settings);
// 	termios_settings.c_lflag &= ~ECHOCTL;
// 	tcsetattr(1, TCSAFLUSH, &termios_settings);
// }

void	signal_ctrl_c(void)
{
	struct sigaction	ctrl_c;

	ctrl_c.sa_handler = NULL; //  a conpleter
	ctrl_c.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_c.sa_mask);
	sigaction(SIGINT, &ctrl_c, NULL);
}

void	signal_ctrl_backslash(void)
{
	struct sigaction	ctrl_back_slash;

	ctrl_back_slash.sa_handler = SIG_IGN;
	ctrl_back_slash.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_back_slash.sa_mask);
	sigaction(SIGQUIT, &ctrl_back_slash, NULL);
}
*/
