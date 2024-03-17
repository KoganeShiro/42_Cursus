/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:53:14 by cejin             #+#    #+#             */
/*   Updated: 2024/03/16 13:53:18 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
	return ;
}

void	error_free(t_pipex *pipex, char	*msg)
{
	ft_putstr_fd(msg, 2);
	ft_cleanup(pipex);
	exit(EXIT_FAILURE);
}
