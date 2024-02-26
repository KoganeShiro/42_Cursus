/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:47:14 by cejin             #+#    #+#             */
/*   Updated: 2024/02/26 11:49:13 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(char **argv, t_pipex *pipex)
{
	pipex->error_flag = 0;
	pipex->outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile_fd < 0)
	{
		perror(argv[4]);
		pipex->error_flag = 1;
	}
	pipex->infile_fd = open(argv[1], O_RDONLY);
	if (pipex->infile_fd < 0)
	{
		perror(argv[1]);
		pipex->error_flag = 1;
	}
}

void	get_path(t_pipex *pipex, char **argv, char **envp)
{
	int		i;
	char	**cmd;
	char	**cmd2;

	cmd = ft_split((const char *)argv[2], " ");
	cmd2 = ft_split((const char *)argv[3], " ");
	pipex->cmd_args1 = cmd;
	pipex->cmd_args2 = cmd2;
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
		pipex->tmp_path = ft_strjoin(pipex->all_paths[i], pipex->cmd_args1[0]);
		pipex->tmp_path2 = ft_strjoin(pipex->all_paths[i], pipex->cmd_args2[0]);
		if (access(pipex->tmp_path, X_OK) != -1)
		{
			pipex->cmd1_exist = 1;
			pipex->cmd_path = pipex->tmp_path;
		}
		if (access(pipex->tmp_path2, X_OK) != -1)
		{
			pipex->cmd2_exist = 1;
			pipex->cmd2_path = pipex->tmp_path2;
			break ;
		}
		free(pipex->tmp_path);
		pipex->tmp_path = NULL;
		free(pipex->tmp_path2);
		pipex->tmp_path2 = NULL;
		i++;
	}
	ft_check_cmd(pipex);
}

void	ft_check_cmd(t_pipex *pipex)
{
	if (pipex->cmd1_exist != 1)
	{
		printf("%s: command not found\n", pipex->cmd_args1[0]);
		pipex->error_flag = 1;
	}
	if (pipex->cmd2_exist != 1)
	{
		printf("%s: command not found\n", pipex->cmd_args2[0]);
		pipex->error_flag = 1;
	}
	if (pipex->error_flag != 0)
	{
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*
int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipe;

	if (argc != 5)
		return (0);
	bzero(&pipe, sizeof(t_pipex));
	check_args(argv, &pipe);
	printf("pipe->infile_fd = %i\n", pipe.infile_fd);
	printf("pipe->outfile_fd = %i\n", pipe.outfile_fd);
	get_path(&pipe, argv, envp);
	return (0);
}
*/
