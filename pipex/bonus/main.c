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

/*
In summary what is my program doing ?

pipex bonus: manage multiple pipes and a heredoc

* multiple pipes
check_args()
	open or create the outfile
	open the infile

get_path()
	fill pipex->all_paths
	if the path doesn't exist
	check_cmd()
		check if the arg is the path of the command
		if yes than fill pipex->cmd_args and pipex->cmd_path
	else the arg is a command so split it and fill pipex->cmd_args

ft_exec()
	while (pipex->nb_of_cmd > 1)
		ft_exec_cmd()
			create a pipe and a fork
			in the child ft_execve()
			use dup2 to redirect the output
			execute the command
	ft_execve_last()
		fork in the child ft_execve()
		use dup2 to redirect the output
		execute the command
wait for all the child to finish

ft_cleanup()
	will free and close all the fd (that i have open)


* heredoc
ft_here_doc()
	check if the limiter is nothing, if it is then when the user will '\n' this will be the delimiter
	open or create the outfile
wrin_heredoc()
	open the heredoc (tmp file)
	write things in it and if the line == to the limiter then delete the file
open the infile (which is the heredoc)

get_path
	fill pipex->all_paths
	if the path doesn't exist
	check_cmd()
		check if the arg is the path of the command
		if yes than fill pipex->cmd_args and pipex->cmd_path
	else the arg is a command so split it and fill pipex->cmd_args

exec_heredoc()
	_exec_()
		create a pipe and a fork
		in the child _execve_()
		use dup2 to redirect the output
		execute the command
		execve the first cmd with the heredoc
	while (pipex->nb_of_cmd > 1)
		ft_exec_cmd()
	ft_execve_last()

*/

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc >= 5)
	{
		bzero(&pipex, sizeof(t_pipex));
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			ft_here_doc(&pipex, argc, argv);
			get_path(&pipex, argv, envp);
			exec_heredoc(&pipex, argv, envp);
		}
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
		write(1, ERROR_MSG, 136);
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
	if (pipex->limiter_flag == 1)
	{
		free(pipex->limiter);
		pipex->limiter = NULL;
	}
	free_tab(pipex->all_paths);
	free_tab(pipex->cmd_args);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}
