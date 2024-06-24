/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 pipex.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cejin <marvin@42.fr>						+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/02/15 17:47:55 by cejin			   #+#	  #+#			  */
/*	 Updated: 2024/02/26 11:52:16 by cejin			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../minishell.h"

/*
	◦ ctrl-\ ---> ^\Quit (core dumped) --> exit_code = 131
	◦ ctrl-c ---> ^C
	◦ ctrl-d ---> *quit without a newline*
*/

void	ft_exec(t_shell *shell, t_command *cmd)
{
	int	i;

	i = shell->nb_of_node;
	shell->tab_envp = NULL;
	shell->tab_envp = env_to_tab(shell->env);
	get_path(shell);
	while (i > 1)
	{
		if (check_files(shell, cmd, 0) == CTRL_C)
			return ;
		cmd = ft_exec_cmd(shell, cmd);
		i--;
	}
	if (check_files(shell, cmd, 1) == CTRL_C)
		return ;
	ft_exec_one(shell, cmd);
}

static int
	_file_error(t_shell *shell, t_command *pipex, int fd[2])
{
	if (pipex->infile_error == 1
		|| pipex->in_fd < 2
		|| (pipex->out_fd < 2 && pipex->outfile_name != NULL))
	{
		pipex->infile_error = 0;
		close(fd[1]);
		if (pipex->out_fd < 2 && pipex->outfile_name != NULL
			&& pipex->in_fd > 2)
			close(pipex->in_fd);
		shell->exit_code = 1;
		return (1);
	}
	return (0);
}

void	_is_heredoc(t_command *cmd)
{
	if (cmd->is_heredoc == 1 || cmd->was_heredoc == 1)
	{
		cmd->was_heredoc = 0;
		cmd->is_heredoc = 0;
		unlink(cmd->heredoc);
		if (cmd->heredoc != NULL)
		{
			free(cmd->heredoc);
			cmd->heredoc = NULL;
		}
		if (cmd->limiter_flag == 1
			&& cmd->limiter != NULL)
		{
			free(cmd->limiter);
			cmd->limiter = NULL;
		}
	}
}

void	_execute(t_shell *shell, t_command *cmd, int fd[2])
{
	if (check_cmd(shell, cmd) != -1)
	{
		shell->pid = fork();
		if (shell->pid == -1)
			ft_error(shell, "fork error\n", EXEC_KO);
		if (shell->pid == 0)
			ft_execve(shell, cmd, fd);
	}
	_is_heredoc(cmd);
	close(cmd->in_fd);
}

t_command	*ft_exec_cmd(t_shell *shell, t_command *cmd)
{
	int		fd[2];
	int		tmp_fd;

	tmp_fd = -1;
	if (pipe(fd) == -1)
		ft_error(shell, "pipe error\n", EXEC_KO);
	if (_file_error(shell, cmd, fd) != 1)
	{
		_execute(shell, cmd, fd);
		close(fd[1]);
		if (cmd->out_fd > 2 && cmd->outfile_name != NULL)
			close(cmd->out_fd);
		tmp_fd = fd[0];
	}
	else
		tmp_fd = fd[0];
	cmd = cmd->next;
	cmd->in_fd = tmp_fd;
	return (cmd);
}
