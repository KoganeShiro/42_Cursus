/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:16:16 by cejin             #+#    #+#             */
/*   Updated: 2024/06/23 13:33:48 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_infile(t_shell *shell, t_command *cmd)
{
	if (cmd->is_heredoc == 1)
		return (ft_here_doc(shell, cmd));
	if (cmd->in_fd > 2)
	{
		if (cmd->was_heredoc == 1)
			_is_heredoc(cmd);
		close(cmd->in_fd);
	}
	cmd->in_fd = open(cmd->infile_name, O_RDONLY);
	if (cmd->in_fd < 0)
	{
		perror(cmd->infile_name);
		cmd->infile_error = 1;
	}
	else
		cmd->infile_error = 0;
	if (cmd->infile_error == 1)
		return (1);
	return (0);
}

int	check_outfile(t_shell *shell, t_command *cmd)
{
	if (cmd->out_fd > 2)
	{
		close(cmd->out_fd);
	}
	if (cmd->append == 1)
		cmd->out_fd = open(cmd->outfile_name, O_WRONLY
				| O_CREAT | O_APPEND, 0644);
	else
		cmd->out_fd = open(cmd->outfile_name, O_WRONLY
				| O_CREAT | O_TRUNC, 0644);
	if (cmd->out_fd < 0)
	{
		perror(cmd->outfile_name);
		shell->exit_code = 1;
		return (1);
	}
	return (0);
}
