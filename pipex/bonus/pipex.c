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

void	create_pipe_fork(t_pipex *pipex, int fd[2])
{
	if (pipe(fd) == -1)
	{
		perror("pipe");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	pipex->pid = fork();
	if (pipex->pid == -1)
	{
		perror("fork");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
}

void	ft_exec_nothing(t_pipex *pipex, int fd[2])
{
	pipex->infile_error = 0;
	close(pipex->in_fd);
	close(fd[0]);
	close(fd[1]);
}

void	ft_exec_cmd(t_pipex *pipex, char **argv, char **envp)
{
	int		fd[2];

	check_cmd(pipex, argv);
	if (pipex->cmd_is_path == 0)
		pipex->cmd_args = ft_split((const char *)argv[pipex->cmd_count], " ");
	create_pipe_fork(pipex, fd);
	if (pipex->pid == 0)
	{
		if (pipex->infile_error == 1)
			ft_exec_nothing(pipex, fd);
		else
			ft_execve(pipex, envp, fd);
	}
	close(fd[1]);
	close(pipex->in_fd);
	pipex->in_fd = fd[0];
}

void	_cmd_is_path(t_pipex *pipex, char **envp)
{
	if (pipex->cmd_is_path == 1)
	{
		execve(pipex->cmd_path, pipex->cmd_args, envp);
		perror("execve (cmd command not found)");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
}
