/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 error_handling.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cejin <marvin@42.fr>						+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/02/21 13:47:14 by cejin			   #+#	  #+#			  */
/*	 Updated: 2024/02/26 11:49:13 by cejin			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_args(int argc, char **argv, t_pipex *pipex)
{
	pipex->cmd = 2;
	pipex->pipe_fd = dup(0);
	pipex->is_first_cmd = 1;
	pipex->outfile_fd = open(argv[argc - 1], O_WRONLY
			| O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile_fd < 0)
	{
		perror(argv[argc - 1]);
		exit(EXIT_FAILURE);
	}
	pipex->infile_fd = open(argv[1], O_RDONLY);
	if (pipex->infile_fd < 0)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
}

void	get_path(t_pipex *pipex, char **envp)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=/", 5) == 0)
		{
			pipex->all_paths = ft_split(envp[i] + 5, ":");
			break ;
		}
		i++;
	}
}

void	ft_exec(t_pipex *pipex, char **argv, char **envp)
{
	ft_exec_first(pipex, argv, envp);
	pipex->nb_of_cmd--;
	pipex->cmd++;
	free_tab(pipex->cmd_args);
	while (pipex->nb_of_cmd > 1)
	{
		ft_exec_cmd(pipex, argv, envp);
		pipex->nb_of_cmd--;
		pipex->cmd++;
		free_tab(pipex->cmd_args);
	}
	ft_execve_last(pipex, argv, envp);
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
