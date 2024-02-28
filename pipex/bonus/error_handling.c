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
	pipex->outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
	ft_execve_first(pipex, argv, envp);
	pipex->nb_of_cmd--;
	pipex->cmd--;
	while (pipex->nb_of_cmd > 0)
	{
		ft_exec_cmd(pipex, argv, envp);
		pipex->nb_of_cmd--;
		pipex->cmd--;
	}
	ft_execve_last(pipex, argv, envp);
}
