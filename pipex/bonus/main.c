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
		write(1, ERROR_MSG, 142);
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
		write(1, ERROR_MSG, 142);
}

/*
int	is_infinite_cmd(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] == NULL)
	{
		if (ft_strncmp(argv[i], "ls", 2) == 0
			|| ft_strncmp(argv[i], "echo", 4) == 0
			|| ft_strncmp(argv[i], "printf", 6) == 0)
			return (i - 4);
		i++;
	}
	return (0);
}

void	ft_wait(t_pipex *pipex, char **argv)
{
	int	i;
	int	cmd;

	i = 0;
	cmd = is_infinite_cmd(argv);
	if (pipex->infile_error == 1)
	{
		if (cmd != 0)
		{
			while (i < (pipex->cmd_count - cmd))
			{
				wait(NULL);
				i++;
			}
		}
	}
	else
	{
		while (i < (pipex->cmd_count))
		{
			wait(NULL);
			i++;
		}
	}
}
*/
