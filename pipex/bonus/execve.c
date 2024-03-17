/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:47:45 by cejin             #+#    #+#             */
/*   Updated: 2024/03/16 15:47:50 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	error_free(pipex, "command not found:");
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
		error_free(pipex, "last command not found");
	}
	close(pipex->in_fd);
}
