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

#include "pipex_bonus.h"

void	ft_exec(t_pipex *pipex, char **argv, char **envp)
{
	int	i;

	i = 0;
	free_tab(pipex->cmd_args);
	free(pipex->cmd_path);
	while (pipex->nb_of_cmd > 1)
	{
		ft_exec_cmd(pipex, argv, envp);
		free_tab(pipex->cmd_args);
		free(pipex->cmd_path);
		pipex->cmd_path = NULL;
		pipex->nb_of_cmd--;
		pipex->cmd_count++;
	}
	check_cmd(pipex, argv);
	if (pipex->cmd_is_path == 0)
		pipex->cmd_args = ft_split((const char *)argv[pipex->cmd_count], " ");
	ft_execve_last(pipex, envp);
	while (i < (pipex->cmd_count))
	{
		wait(NULL);
		i++;
	}
}

int	check_infile(t_pipex *pipex, int fd[2])
{
	if (pipex->first_cmd == 1)
	{
		pipex->first_cmd = 0;
		if (pipex->infile_error == 1)
		{
			pipex->in_fd = open("/dev/null", O_RDONLY);
			dup2(pipex->in_fd, STDIN_FILENO);
			close(fd[0]);
			close(pipex->in_fd);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			return (1);
		}
	}
	return (0);
}

void	ft_exec_cmd(t_pipex *pipex, char **argv, char **envp)
{
	int		fd[2];

	check_cmd(pipex, argv);
	if (pipex->cmd_is_path == 0)
		pipex->cmd_args = ft_split((const char *)argv[pipex->cmd_count], " ");
	if (pipe(fd) == -1)
		error_free(pipex, "pipe error");
	if (check_infile(pipex, fd) == 0)
	{
		pipex->pid = fork();
		if (pipex->pid == -1)
			error_free(pipex, "fork error");
		if (pipex->pid == 0)
			ft_execve(pipex, envp, fd);
		close(fd[1]);
		close(pipex->in_fd);
		pipex->in_fd = fd[0];
	}
}

void	_cmd_is_path(t_pipex *pipex, char **envp)
{
	if (pipex->cmd_is_path == 1)
	{
		execve(pipex->cmd_path, pipex->cmd_args, envp);
		error_free(pipex, "command path not found");
	}
}
