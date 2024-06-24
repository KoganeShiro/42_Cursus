/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:47:45 by cejin             #+#    #+#             */
/*   Updated: 2024/06/23 15:07:26 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	_cmd_is_path(t_shell *shell, t_command *cmd)
{
	if (cmd->cmd_is_path == 1)
	{
		if (access(cmd->cmd_path, X_OK) == -1)
		{
			ft_error(shell, "No access to command\n", EXEC_KO);
			free_child(shell, cmd);
		}
		else
		{
			execve(cmd->cmd_path, cmd->cmd_args, shell->tab_envp);
			ft_error(shell, "command not found\n", CMD_NOT_FOUND);
			free_child(shell, cmd);
		}
	}
}

void	ft_execve_loop(t_shell *shell, t_command *cmd)
{
	int		i;

	i = 0;
	_cmd_is_path(shell, cmd);
	while (shell->all_paths[i] != NULL)
	{
		free(cmd->cmd_path);
		cmd->cmd_path = pipex_join(shell->all_paths[i],
				cmd->cmd_args[0], '/');
		if (access(cmd->cmd_path, X_OK) != -1)
		{
			execve(cmd->cmd_path, cmd->cmd_args, shell->tab_envp);
			ft_error(shell, "No access to command\n", EXEC_KO);
			free_child(shell, cmd);
		}
		i++;
	}
	ft_error(shell, "command not found\n", CMD_NOT_FOUND);
	free_child(shell, cmd);
}

void	ft_execve(t_shell *shell, t_command *cmd, int fd[2])
{
	int		i;

	i = 0;
	get_signal(1);
	ft_redirection(cmd, fd);
	if (handle_builtins(shell, cmd) == true)
	{
		close(fd[0]);
		free_child(shell, cmd);
	}
	close(fd[0]);
	ft_execve_loop(shell, cmd);
}

int	_manage_builtins(t_shell *shell, t_command *cmd, int state)
{
	int	builtin_state;

	builtin_state = is_builtins(cmd);
	if (builtin_state == -1)
		return (-1);
	if (builtin_state == state && state == 2)
	{
		if (handle_builtins(shell, cmd) == true)
			return (5);
	}
	else if (builtin_state == state && shell->nb_of_cmd == 1)
	{
		if (handle_builtins(shell, cmd) == true)
			return (10);
	}
	return (-1);
}

//can be the first or the last cmd
void	ft_exec_one(t_shell *shell, t_command *cmd)
{
	if (check_cmd(shell, cmd) == -1)
		return ;
	if (cmd->infile_error == 1
		|| (cmd->out_fd < 2 && cmd->outfile_name != NULL))
	{
		cmd->infile_error = 0;
		shell->exit_code = GEN_ERR;
		return ;
	}
	get_signal(1);
	if (_manage_builtins(shell, cmd, 1) == 10)
		return ;
	shell->pid = fork();
	if (shell->pid == -1)
		ft_error(shell, "fork error\n", EXEC_KO);
	shell->has_fork = 1;
	if (shell->pid == 0)
	{
		ft_last_redir(cmd);
		if (_manage_builtins(shell, cmd, 2) == 5)
			free_child(shell, cmd);
		ft_execve_loop(shell, cmd);
	}
}
