/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:45:14 by cejin             #+#    #+#             */
/*   Updated: 2024/06/23 15:08:35 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_redirection(t_command *cmd, int fd[2])
{
	if (ft_strcmp(cmd->cmd_args[0], "exit") == 0)
		close(fd[0]);
	if (cmd->in_fd > 2)
	{
		if (dup2(cmd->in_fd, STDIN_FILENO) == -1)
			perror("dup2 in_fd");
		close(cmd->in_fd);
	}
	if (cmd->outfile_name != NULL && cmd->out_fd > 2)
	{
		if (dup2(cmd->out_fd, STDOUT_FILENO) == -1)
			perror("outfile dup2 out_fd");
		close(cmd->out_fd);
		close(fd[1]);
	}
	else
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			perror("dup2 fd[1]");
		close(fd[1]);
	}
}

void	ft_last_redir(t_command *cmd)
{
	if (dup2(cmd->in_fd, STDIN_FILENO) == -1)
		perror("single or last dup2 in_fd");
	close(cmd->in_fd);
	if (dup2(cmd->out_fd, STDOUT_FILENO) == -1)
		perror("single or last dup2 out_fd");
	close(cmd->out_fd);
}
