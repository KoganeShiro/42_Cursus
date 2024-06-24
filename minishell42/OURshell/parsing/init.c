/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:03:28 by vharatyk          #+#    #+#             */
/*   Updated: 2024/06/16 18:12:41 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	init_shell(t_shell *shell)
{
	shell->cmd = NULL;
	shell->end = 1;
	shell->status = 0;
	shell->pid = getpid();
	shell->exit_code = 0;
	shell->nb_of_cmd = 0;
	shell->heredoc_i = 0;
	shell->create_node = 0;
	shell->all_paths = NULL;
	shell->tab_envp = NULL;
	shell->has_fork = 0;
	return (0);
}

void	init_cmd_bool(t_command *cmd)
{
	cmd->append = 0;
	cmd->is_heredoc = 0;
	cmd->infile_name = NULL;
	cmd->outfile_name = NULL;
	cmd->limiter_flag = 0;
	cmd->cmd_is_path = 0;
}

void	init_command(t_command *new_cmd)
{
	new_cmd->outfile_error = 0;
	new_cmd->infile_error = 0;
	new_cmd->append = 0;
	new_cmd->first_node = 0;
	new_cmd->last_node = 0;
	new_cmd->out_fd = -1;
	new_cmd->in_fd = -1;
	new_cmd->infile_name = NULL;
	new_cmd->outfile_name = NULL;
	new_cmd->heredoc = NULL;
	new_cmd->limiter = NULL;
	new_cmd->limiter_flag = 0;
	new_cmd->cmd_args = NULL;
	new_cmd->cmd_path = NULL;
	new_cmd->cmd_is_path = 0;
	new_cmd->ctrlc = 0;
	new_cmd->was_heredoc = 0;
	new_cmd->has_in_redir = 0;
	new_cmd->has_out_redir = 0;
}

void	init_input(t_input *input)
{
	input->trigger = 0;
	input->lst = NULL;
	input->tab = 0;
	input->len = 0;
	input->index = 0;
	input->i = 0;
	input->j = 0;
}
