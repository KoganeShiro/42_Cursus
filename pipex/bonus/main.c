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

	if (argc >= 3)
	{
		bzero(&pipex, sizeof(t_pipex));
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
			launch_heredoc(&pipex, argc, argv, envp);
		else
		{
			pipex.nb_of_cmd = argc - 3;
			check_args(argc, argv, &pipex);
			get_path(&pipex, argv, envp);
			ft_exec(&pipex, argv, envp);
		}
		ft_cleanup(&pipex);
	}
	else
		ft_putstr_fd(ERROR_MSG, 2);
	return (0);
}

void	launch_heredoc(t_pipex *pipex, int argc, char **argv, char **envp)
{
	if (argc >= 6)
	{
		ft_here_doc(pipex, argc, argv);
		get_path(pipex, argv, envp);
		exec_heredoc(pipex, argv, envp);
	}
	else
		ft_putstr_fd(ERROR_MSG, 2);
}
