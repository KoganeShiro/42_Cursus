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

void	ft_execve_first(t_pipex *pipex, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		i = 0;

	printf("first cmd %s\n", argv[pipex->cmd]); //DEBUGGING
	pipex->cmd_args = ft_split((const char *)argv[pipex->cmd], " ");
	if (pipe(fd) == -1)
	{
		perror("pipe");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		dup2(pipex->infile_fd, STDIN_FILENO);
		close(pipex->infile_fd);
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		while (pipex->all_paths[i] != NULL)
		{
			free(pipex->cmd_path);
			pipex->cmd_path = ft_strjoin(pipex->all_paths[i], pipex->cmd_args[0]);
			execve(pipex->cmd_path, pipex->cmd_args, envp);
			i++;
		}
		perror("execve (cmd command not found)");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	close(pipex->pipe_fd);
	pipex->pipe_fd = fd[0];
	waitpid(pid, NULL, 0);
}

void	ft_exec_cmd(t_pipex *pipex, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	pipex->cmd_args = ft_split((const char *)argv[pipex->cmd], " ");
	if (pipe(fd) == -1)
	{
		perror("pipe");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		ft_execve(pipex, envp, fd);
	close(fd[1]);
	close(pipex->pipe_fd);
	pipex->pipe_fd = fd[0];
	waitpid(pid, NULL, 0);
}

void	ft_execve(t_pipex *pipex, char **envp, int fd[2])
{
	int		i;

	i = 0;
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(pipex->pipe_fd, STDIN_FILENO);
	close(pipex->pipe_fd);
	while (pipex->all_paths[i] != NULL)
	{
		free(pipex->cmd_path);
		pipex->cmd_path = ft_strjoin(pipex->all_paths[i], pipex->cmd_args[0]);
		execve(pipex->cmd_path, pipex->cmd_args, envp);
		i++;
	}
	perror("execve (cmd command not found)");
	ft_cleanup(pipex);
	exit(EXIT_FAILURE);
}

void	ft_execve_last(t_pipex *pipex, char **argv, char **envp)
{
	pid_t	pid;
	int		i;

	i = 0;
	pipex->cmd_args = ft_split((const char *)argv[pipex->cmd], " ");
	pid = fork();
	if (pid == 0)
	{
		dup2(pipex->pipe_fd, STDIN_FILENO);
		close(pipex->pipe_fd);
		dup2(pipex->outfile_fd, STDOUT_FILENO);
		close(pipex->outfile_fd);
		while (pipex->all_paths[i] != NULL)
		{
			free(pipex->cmd_path);
			pipex->cmd_path = ft_strjoin(pipex->all_paths[i], pipex->cmd_args[0]);
			execve(pipex->cmd_path, pipex->cmd_args, envp);
			i++;
		}
		perror("execve (cmd2 command not found)");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	waitpid(pid, NULL, 0);
}
