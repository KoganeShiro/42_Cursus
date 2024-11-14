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

char	*ft_strdup_modif(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	res = ft_calloc(i, sizeof(char));
	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
