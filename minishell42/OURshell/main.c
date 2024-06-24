/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:24:48 by vharatyk          #+#    #+#             */
/*   Updated: 2024/06/23 13:07:27 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	_ft_wait(t_shell *shell)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	waitpid(shell->pid, &status, 0);
	while (i < (shell->nb_of_cmd - 1))
	{
		wait(NULL);
		i++;
	}
	if (shell->has_fork == 0)
		shell->status = shell->exit_code;
	else
	{
		if (WIFEXITED(status))
			shell->status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			shell->status = 128 + WTERMSIG(status);
	}
}

void	_ft_input(t_shell *shell, t_input *input)
{
	if (input->str[0] == '\0')
		return ;
	if (input->str)
		add_history(input->str);
	if (parsing(shell, input) == 0)
	{
		shell->exit_code = 0;
		ft_exec(shell, shell->cmd);
		ft_cleanup(shell, shell->cmd, 0);
		_ft_wait(shell);
		free_input(input);
		free_input(shell->input);
	}
	check_exitcode(shell);
	shell->has_fork = 0;
}

int	shell_loop(t_shell *shell, t_input *input)
{
	while (shell->end != 0)
	{
		get_signal(0);
		init_input(input);
		input->str = readline(RED "OURShell☭: " RESET);
		if (input->str != NULL)
		{
			_ft_input(shell, input);
			free(input->str);
			input->str = NULL;
		}
		else
		{
			check_exitcode(shell);
			break ;
		}
	}
	return (0);
}

int	main(int argc, char *argv[], char **envp)
{
	t_shell	shell;
	t_input	input;

	rl_outstream = stderr;
	if (argc != 1 && argv[1])
	{
		ft_putstr_fd(2, "Usage: ./minishell");
		exit(0);
	}
	init_shell(&shell);
	shell.env = convert_envp(envp);
	shell_loop(&shell, &input);
	ft_exit(&shell, shell.cmd, false);
	return (shell.exit_code);
}
