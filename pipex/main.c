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

#include "pipex.h"

/*
In summary what is my program doing ?

check_args()
	open or create the outfile
	open the infile

get_path()
	check_cmd1()
	check_cmd2()
		if the arg is not a command but the path of the command
		if it is then fill the pipex->cmd_args1 and pipex->cmd_args2
		pipex->cmd_path and pipex->cmd2_path
	the arg is a command, so it will split it and fill the pipex->cmd_args1 and pipex->cmd_args2
	and fill pipex->all_paths

call is_cmd_exist()
	is_cmd2_exist()
		fill the pipex->cmd_path and pipex->cmd2_path

exec_cmd()
	create a pipe and a fork
	in the child exec_cmd1()
		use dup2 to redirect the output
		execute the command
	exec_cmd2()
		fork and in the child
		use dup2 to redirect the output
		execute the command

ft_cleanup()
	will free and close the fd
*/

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc == 5)
	{
		ft_bzero(&pipex, sizeof(t_pipex));
		free(pipex.cmd_path);
		pipex.cmd_path = NULL;
		free(pipex.cmd2_path);
		pipex.cmd2_path = NULL;
		check_args(argv, &pipex);
		check_cmd1(&pipex, argv);
		if (pipex.cmd_is_path == 0)
			pipex.cmd_args1 = ft_split((const char *)argv[2], " ");
		check_cmd2(&pipex, argv);
		if (pipex.cmd2_is_path == 0)
			pipex.cmd_args2 = ft_split((const char *)argv[3], " ");
		get_path(&pipex, envp);
		exec_cmd(&pipex, envp);
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
	if (pipex->tmp_path)
	{
		free(pipex->tmp_path);
		pipex->tmp_path = NULL;
	}
	if (pipex->tmp_path2)
	{
		free(pipex->tmp_path2);
		pipex->tmp_path2 = NULL;
	}
	if (pipex->cmd_path)
	{
		free(pipex->cmd_path);
		pipex->cmd_path = NULL;
	}
	if (pipex->cmd2_path)
	{
		free(pipex->cmd2_path);
		pipex->cmd2_path = NULL;
	}
	free_tab(pipex->all_paths);
	free_tab(pipex->cmd_args1);
	free_tab(pipex->cmd_args2);
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
		i++;
	}
	free(tab);
	tab = NULL;
}
