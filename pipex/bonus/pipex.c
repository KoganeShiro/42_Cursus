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
	while (pipex->nb_of_cmd > 1)
	{
		ft_exec_cmd(pipex, argv, envp);
		pipex->nb_of_cmd--;
		pipex->cmd_count++;
		free_tab(pipex->cmd_args);
	}
	check_cmd(pipex, argv);
	if (pipex->cmd_is_path == 0)
		pipex->cmd_args = ft_split((const char *)argv[pipex->cmd_count], " ");
	ft_execve_last(pipex, envp);
	while (i < pipex->cmd_count)
	{
		wait(NULL);
		i++;
	}
}

void	ft_exec_cmd(t_pipex *pipex, char **argv, char **envp)
{
	int		fd[2];

	check_cmd(pipex, argv);
	if (pipex->cmd_is_path == 0)
		pipex->cmd_args = ft_split((const char *)argv[pipex->cmd_count], " ");
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
	if (pipex->pid == 0)
		ft_execve(pipex, envp, fd);
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

void	ft_execve(t_pipex *pipex, char **envp, int fd[2])
{
	int		i;

	i = 0;
	dup2(pipex->in_fd, STDIN_FILENO);
	close(pipex->in_fd);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	_cmd_is_path(pipex, envp);
	while (pipex->all_paths[i] != NULL)
	{
		free(pipex->cmd_path);
		pipex->cmd_path = ft_strjoin(pipex->all_paths[i],
				pipex->cmd_args[0]);
		execve(pipex->cmd_path, pipex->cmd_args, envp);
		i++;
	}
	perror("execve (cmd command not found)");
	ft_cleanup(pipex);
	exit(EXIT_FAILURE);
}

void	ft_execve_last(t_pipex *pipex, char **envp)
{
	int		i;
	pid_t	pid;

	i = 0;
	pid = fork();
	if (pid == 0)
	{
		dup2(pipex->in_fd, STDIN_FILENO);
		close(pipex->in_fd);
		dup2(pipex->outfile_fd, STDOUT_FILENO);
		close(pipex->outfile_fd);
		_cmd_is_path(pipex, envp);
		while (pipex->all_paths[i] != NULL)
		{
			free(pipex->cmd_path);
			pipex->cmd_path = ft_strjoin(pipex->all_paths[i],
					pipex->cmd_args[0]);
			execve(pipex->cmd_path, pipex->cmd_args, envp);
			i++;
		}
		perror("execve (cmd2 command not found)");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	close(pipex->in_fd);
}
