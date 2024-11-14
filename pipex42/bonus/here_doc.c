/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 here_doc.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cejin <marvin@42.fr>						+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/02/29 18:40:08 by cejin			   #+#	  #+#			  */
/*	 Updated: 2024/02/29 18:40:36 by cejin			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_heredoc(t_pipex *pipex, char **argv, char **envp)
{
	int	i;

	i = 0;
	_exec_(pipex, envp);
	pipex->nb_of_cmd--;
	pipex->cmd_count++;
	free_tab(pipex->cmd_args);
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

void	_exec_(t_pipex *pipex, char **envp)
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
		_execve_(pipex, envp, fd);
	if (pipex->in_fd)
		unlink("/tmp/heredoc");
	close(fd[1]);
	close(pipex->in_fd);
	pipex->in_fd = fd[0];
}

void	_execve_(t_pipex *pipex, char **envp, int fd[2])
{
	int		i;

	i = 0;
	dup2(pipex->in_fd, STDIN_FILENO);
	close(pipex->in_fd);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
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

int	_condition(t_pipex *pipex, char *line)
{
	if (pipex->limiter_flag == 1)
	{
		if (ft_strlen(pipex->limiter) == ft_strlen(line)
			&& ft_strncmp(line, pipex->limiter, 1) == 0)
		{
			return (1);
		}
	}
	else
	{
		if (ft_strlen(pipex->limiter) + 1 == ft_strlen(line)
			&& ft_strncmp(line, pipex->limiter,
				ft_strlen(pipex->limiter)) == 0)
		{
			return (1);
		}
	}
	return (0);
}

void	wrin_heredoc(t_pipex *pipex, char *line)
{
	int		heredoc_fd;

	heredoc_fd = open("/tmp/heredoc", O_CREAT
			| O_WRONLY | O_TRUNC, 0644);
	if (heredoc_fd < 0)
	{
		perror("/tmp/heredoc");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO, pipex);
		if (_condition(pipex, line) == 1)
			break ;
		write(heredoc_fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	line = NULL;
	close(heredoc_fd);
}
