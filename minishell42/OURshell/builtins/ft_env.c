/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:36:16 by cejin             #+#    #+#             */
/*   Updated: 2024/06/24 15:40:12 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env(t_shell *shell, t_command *cmd)
{
	t_env	*current;

	current = shell->env;
	while (current != NULL)
	{
		if ((current->key == NULL || current->value == NULL)
			|| cmd->cmd_args[1] != NULL)
		{
			if (current->key == NULL || current->value == NULL)
				ft_error(shell, "No ENV found\n", CMD_NOT_FOUND);
			if (cmd->cmd_args[1] != NULL)
				ft_error(shell, ": command not found\n", CMD_NOT_FOUND);
			free_child(shell, cmd);
		}
		else
		{
			ft_putstr_fd(1, current->key);
			ft_putstr_fd(1, "=");
			ft_putstr_fd(1, current->value);
			write(1, "\n", 1);
		}
		current = current->next;
	}
	return (shell->exit_code);
}
