/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 main.c												:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cejin <marvin@42.fr>						+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/02/27 16:40:32 by cejin			   #+#	  #+#			  */
/*	 Updated: 2024/02/27 16:40:34 by cejin			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc >= 5)
	{
		bzero(&pipex, sizeof(t_pipex));
		pipex.nb_of_cmd = argc - 3;
		pipex.cmd = 2;
		pipex.pipe_fd = dup(0);
		check_args(argc, argv, &pipex);
		get_path(&pipex, envp);
		ft_exec(&pipex, argv, envp);
		ft_cleanup(&pipex);
	}
	else
		write(1, ERROR_MSG, 75);
	return (0);
}

void	ft_cleanup(t_pipex *pipex)
{
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
	close(pipex->pipe_fd);
	if (pipex->cmd_path)
	{
		free(pipex->cmd_path);
		pipex->cmd_path = NULL;
	}
	free_tab(pipex->all_paths);
	pipex->all_paths = NULL;
	free_tab(pipex->cmd_args);
	pipex->cmd_args = NULL;
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
	tab = NULL;
}
