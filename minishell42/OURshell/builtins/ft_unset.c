/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:04:47 by cejin             #+#    #+#             */
/*   Updated: 2024/06/23 13:32:10 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*exec_unset(t_shell *shell, t_command *cmd, t_env *cur, int i)
{
	t_env	*prev;

	prev = NULL;
	if (cmd->cmd_args[i][0] == '-')
	{
		ft_error(shell, "unset: -: invalid option\n", 2);
		return (shell->env);
	}
	while (cur != NULL)
	{
		if (ft_strcmp(cur->key, cmd->cmd_args[i]) == 0)
		{
			if (prev == NULL)
				shell->env = cur->next;
			else
				prev->next = cur->next;
			free_env_node(cur);
			return (shell->env);
		}
		prev = cur;
		cur = cur->next;
	}
	return (shell->env);
}

int	ft_unset(t_shell *shell, t_command *cmd, t_env *tmp)
{
	int		i;

	i = 1;
	if (cmd->cmd_args == NULL)
		return (0);
	while (cmd->cmd_args[i] != NULL)
	{
		tmp = shell->env;
		shell->env = exec_unset(shell, cmd, tmp, i);
		if (shell->exit_code != 0)
			break ;
		i++;
	}
	return (shell->exit_code);
}
