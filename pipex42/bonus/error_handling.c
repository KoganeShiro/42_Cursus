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
	pipex->cmd_count = 2;
	pipex->infile_error = 0;
	pipex->first_cmd = 1;
	pipex->outfile_fd = open(argv[argc - 1], O_WRONLY
			| O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile_fd < 0)
	{
		perror(argv[argc - 1]);
		exit(EXIT_FAILURE);
	}
	pipex->in_fd = open(argv[1], O_RDONLY);
	if (pipex->in_fd < 0)
	{
		perror(argv[1]);
		pipex->infile_error = 1;
	}
	else
		pipex->infile_error = 0;
}

void	ft_here_doc(t_pipex *pipex, int argc, char **argv)
{
	pipex->limiter = argv[2];
	pipex->nb_of_cmd = argc - 4;
	pipex->cmd_count = 3;
	if (pipex->limiter == NULL || pipex->limiter[0] == '\0')
	{
		pipex->limiter = ft_strdup("\n");
		pipex->limiter_flag = 1;
	}
	pipex->outfile_fd = open(argv[argc - 1], O_WRONLY
			| O_CREAT | O_APPEND, 0644);
	if (pipex->outfile_fd < 0)
	{
		perror(argv[argc - 1]);
		exit(EXIT_FAILURE);
	}
	wrin_heredoc(pipex, NULL);
	pipex->in_fd = open("/tmp/heredoc", O_RDONLY, 0644);
	if (pipex->in_fd < 0)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
}

void	get_path(t_pipex *pipex, char **argv, char **envp)
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
	check_cmd(pipex, argv);
	if (pipex->all_paths == NULL && pipex->cmd_is_path != 0)
	{
		write(2, "Path not found\n", 15);
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	if (pipex->cmd_is_path == 0)
		pipex->cmd_args = ft_split((const char *)argv[pipex->cmd_count], " ");
}

void	check_cmd(t_pipex *p, char **argv)
{
	int		i;

	p->cmd_is_path = 0;
	i = ft_strlen(argv[p->cmd_count]);
	while (i >= 0)
	{
		if (ft_strncmp(&argv[p->cmd_count][i], "/", 1) == 0)
		{
			if (ft_strchr(argv[p->cmd_count] + (i + 1), ' ') == 0)
			{
				p->cmd_args = ft_calloc(2, sizeof(char *));
				p->cmd_args[0] = ft_strdup(argv[p->cmd_count] + (i + 1));
				p->cmd_args[1] = NULL;
				p->cmd_path = ft_strdup(argv[p->cmd_count]);
			}
			else
			{
				p->cmd_args = ft_split(argv[p->cmd_count] + (i + 1), " ");
				p->cmd_path = _m_strdup(argv[p->cmd_count]);
			}
			p->cmd_is_path = 1;
			break ;
		}
		i--;
	}
}
