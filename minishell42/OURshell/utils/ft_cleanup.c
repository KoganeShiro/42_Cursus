/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:53:14 by cejin             #+#    #+#             */
/*   Updated: 2024/06/21 12:23:16 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_child(t_shell *shell, t_command *cmd)
{
	ft_cleanup(shell, cmd, 1);
	free(shell->input->str);
	shell->input->str = NULL;
	free_input(shell->input);
	free_envp(&shell->env);
	rl_clear_history();
	exit(shell->exit_code);
}

void	ft_putstr_fd(int fd, char *s)
{
	int	len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
	return ;
}

static void	free_cmd(t_shell *shell, t_command *cmd)
{
	t_command	*current;
	t_command	*next;

	free_tab(shell->all_paths);
	free_tab(shell->tab_envp);
	current = cmd;
	if (current == NULL)
		return ;
	while (current != NULL)
	{
		next = current->next;
		if (current->cmd_path != NULL)
			free(current->cmd_path);
		if (current->cmd_args != NULL)
			free(current->cmd_args);
		if (current != NULL)
			free(current);
		current = next;
	}
	if (current != NULL)
		free(current);
	cmd = NULL;
}

void	ft_cleanup(t_shell *shell, t_command *cmd, bool child)
{
	if (child == 0)
	{
		while (cmd->next != NULL)
		{
			if (cmd->ctrlc == 1)
				break ;
			if (shell->exit_code == CTRL_C)
			{
				if (cmd->in_fd > 2)
					close(cmd->in_fd);
				if (cmd->out_fd > 2)
					close(cmd->out_fd);
				if (cmd->was_heredoc == 1)
					_is_heredoc(cmd);
			}
			cmd = cmd->next;
		}
	}
	if (cmd->in_fd > 2)
		close(cmd->in_fd);
	if (cmd->out_fd > 2)
		close(cmd->out_fd);
	_is_heredoc(cmd);
	free_cmd(shell, shell->cmd);
}

int	ft_error(t_shell *shell, char *msg, int exit_code)
{
	shell->exit_code = exit_code;
	if (msg == NULL)
		return (exit_code);
	ft_putstr_fd(2, msg);
	return (exit_code);
}
