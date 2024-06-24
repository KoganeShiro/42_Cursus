/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:25:59 by cejin             #+#    #+#             */
/*   Updated: 2024/06/23 13:36:08 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_files(t_shell *shell, t_command *cmd, bool last)
{
	static int	i = 0;

	if (shell->input->tab[i] == PIPE)
		i++;
	i = _check_redir(shell, cmd, i);
	if (cmd->has_in_redir == 0 && (cmd->first_node == 1
			|| shell->nb_of_node == 1))
	{
		cmd->in_fd = dup(STDIN_FILENO);
	}
	if (cmd->has_out_redir == 0 && (cmd->last_node == 1
			|| shell->nb_of_node == 1))
	{
		cmd->out_fd = dup(STDOUT_FILENO);
	}
	if (last == 1)
		i = 0;
	return (shell->exit_code);
}

int	_check_redir(t_shell *shell, t_command *cmd, int i)
{
	if (shell->input->lst != NULL || shell->input->tab != 0)
	{
		while (shell->input->tab[i] != 0
			&& shell->input->tab[i] != PIPE)
		{
			if (shell->input->tab[i] == INREDIR)
				i = _init_files(shell, cmd, INREDIR, i);
			else if (shell->input->tab[i] == OUTREDIR)
				i = _init_files(shell, cmd, OUTREDIR, i);
			else if (shell->input->tab[i] == HEREDOC)
				i = _init_files(shell, cmd, HEREDOC, i);
			else if (shell->input->tab[i] == APPEND)
				i = _init_files(shell, cmd, APPEND, i);
			if (g_sig == SIGINT)
				return (CTRL_C);
			i++;
		}
	}
	return (i);
}

int	file_has_error(t_shell *shell, t_command *cmd, int i)
{
	cmd->infile_name = NULL;
	while (shell->input->tab[i + 1] != 0
		&& shell->input->tab[i + 1] != PIPE)
	{
		i++;
	}
	shell->exit_code = 1;
	return (i);
}

int	_init_infile(t_shell *shell, t_command *cmd, int redir, int i)
{
	cmd->has_in_redir = 1;
	if (redir == HEREDOC)
	{
		cmd->is_heredoc = 1;
		if (cmd->limiter != NULL)
			cmd->limiter = NULL;
		cmd->limiter = shell->input->lst[i + 1];
	}
	else
		cmd->infile_name = shell->input->lst[i + 1];
	if (check_infile(shell, cmd) == 1)
		i = file_has_error(shell, cmd, i);
	return (i);
}

int	_init_files(t_shell *shell, t_command *cmd, int redir, int i)
{
	init_cmd_bool(cmd);
	if (redir == OUTREDIR || redir == APPEND)
	{
		cmd->has_out_redir = 1;
		cmd->outfile_name = shell->input->lst[i + 1];
		if (redir == APPEND)
			cmd->append = 1;
		if (check_outfile(shell, cmd) == 1)
			i = file_has_error(shell, cmd, i);
	}
	else if (redir == INREDIR || redir == HEREDOC)
	{
		i = _init_infile(shell, cmd, redir, i);
	}
	return (i);
}
