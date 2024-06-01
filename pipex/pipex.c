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

#include "pipex.h"

void	get_path(t_pipex *pipex, char **envp)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=/", 5) == 0)
		{
			pipex->all_paths = ft_split(envp[i] + 5, ":");
			is_cmd_exist(pipex);
			is_cmd2_exist(pipex);
			break ;
		}
		i++;
	}
	if (pipex->all_paths == NULL)
	{
		write(2, "Path not found\n", 15);
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
}

void	exec_cmd(t_pipex *pipex, char **envp)
{
	int		fd[2];
	pid_t	pid;

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
		exec_cmd1(pipex, envp, fd);
	close(fd[1]);
	exec_cmd2(pipex, envp, fd);
	waitpid(pid, NULL, 0);
}

void	exec_cmd1(t_pipex *pipex, char **envp, int fd[2])
{
	close(fd[0]);
	if (pipex->infile_error == 0)
	{
		dup2(pipex->infile_fd, STDIN_FILENO);
		close(pipex->infile_fd);
	}
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve(pipex->cmd_path, pipex->cmd_args1, envp);
	perror("execve (cmd1 command not found)");
	ft_cleanup(pipex);
	exit(EXIT_FAILURE);
}

void	exec_cmd2(t_pipex *pipex, char **envp, int fd[2])
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork (bis)");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		dup2(pipex->outfile_fd, STDOUT_FILENO);
		close(pipex->outfile_fd);
		execve(pipex->cmd2_path, pipex->cmd_args2, envp);
		perror("execve (cmd2 command not found)");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	waitpid(pid2, NULL, 0);
}

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*src;

	src = (char *)s;
	i = 0;
	while (n != 0)
	{
		src[i] = 0;
		i++;
		n--;
	}
	return ;
}
