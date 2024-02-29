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

#include "pipex.h"

void	check_args(char **argv, t_pipex *pipex)
{
	pipex->outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile_fd < 0)
	{
		perror(argv[4]);
		exit(EXIT_FAILURE);
	}
	pipex->infile_fd = open(argv[1], O_RDONLY);
	if (pipex->infile_fd < 0)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
}

void	get_path(t_pipex *pipex, char **argv, char **envp)
{
	int		i;

	pipex->cmd_args1 = ft_split((const char *)argv[2], " ");
	pipex->cmd_args2 = ft_split((const char *)argv[3], " ");
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=/", 5) == 0)
		{
			pipex->all_paths = ft_split(envp[i] + 5, ":");
			is_cmd_exist(pipex);
			exec_cmd(pipex, envp);
			break ;
		}
		i++;
	}
}

void	is_cmd_exist(t_pipex *pipex)
{
	int		i;

	i = 0;
	while (pipex->all_paths[i] != NULL)
	{
		free(pipex->tmp_path);
		free(pipex->tmp_path2);
		pipex->tmp_path = ft_strjoin(pipex->all_paths[i], pipex->cmd_args1[0]);
		pipex->tmp_path2 = ft_strjoin(pipex->all_paths[i], pipex->cmd_args2[0]);
		if (access(pipex->tmp_path, X_OK) != -1)
		{
			free(pipex->cmd_path);
			pipex->cmd_path = ft_strdup(pipex->tmp_path);
			pipex->flag_cmd1 = 1;
		}
		if (access(pipex->tmp_path2, X_OK) != -1)
		{
			free(pipex->cmd2_path);
			pipex->cmd2_path = ft_strdup(pipex->tmp_path2);
			pipex->flag_cmd2 = 1;
		}
		if (pipex->all_paths[i + 1] == NULL)
			break ;
		i++;
	}
}
