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
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			ft_here_doc(&pipex, argc, argv);
			get_path(&pipex, envp);
			exec_heredoc(&pipex, argv, envp);
		}
		else
		{
			pipex.nb_of_cmd = argc - 3;
			check_args(argc, argv, &pipex);
			get_path(&pipex, envp);
			ft_exec(&pipex, argv, envp);
		}
		ft_cleanup(&pipex);
	}
	else
		write(1, ERROR_MSG, 75);
	return (0);
}

void	ft_cleanup(t_pipex *pipex)
{
	close(pipex->in_fd);
	close(pipex->outfile_fd);
	if (pipex->cmd_path)
	{
		free(pipex->cmd_path);
		pipex->cmd_path = NULL;
	}
	free_tab(pipex->all_paths);
	free_tab(pipex->cmd_args);
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
