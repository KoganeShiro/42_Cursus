/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:22:40 by cejin             #+#    #+#             */
/*   Updated: 2024/06/23 13:31:51 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static bool	get_exitcode(t_shell *shell, t_command *cmd);

void
	ft_exit(t_shell *shell, t_command *cmd, bool builtin)
{
	if (shell->nb_of_cmd == 1)
		write(2, "exit\n", 5);
	if (builtin == true)
	{
		if (get_exitcode(shell, cmd) == false)
			return ;
	}
	rl_clear_history();
	if (builtin == true)
	{
		ft_cleanup(shell, cmd, 0);
		free(shell->input->str);
		free_input(shell->input);
	}
	free_envp(&shell->env);
	exit(shell->exit_code);
}

static bool	right_exitcode(char *exitcode, int i, bool found_nb)
{
	while (exitcode[i] != '\0')
	{
		if (found_nb == true && is_space(exitcode[i]) == false)
			return (false);
		else if (!is_space(exitcode[i])
			&& !(exitcode[i] >= '0' && exitcode[i] <= '9')
			&& !(exitcode[i] == '-' || exitcode[i] == '+'))
			return (false);
		else if (is_space(exitcode[i]) == true)
			i++;
		else if ((exitcode[i] == '-' || exitcode[i] == '+')
			|| (exitcode[i] >= '0' && exitcode[i] <= '9'))
		{
			i++;
			while (exitcode[i] >= '0' && exitcode[i] <= '9')
				i++;
			found_nb = true;
		}
	}
	if (found_nb == false)
		return (false);
	return (true);
}

static bool	get_exitcode(t_shell *shell, t_command *cmd)
{
	if (cmd->cmd_args[1] == NULL)
		return (true);
	if (cmd->cmd_args[2] != NULL
		&& right_exitcode(cmd->cmd_args[1], 0, false) == true)
	{
		ft_error(shell, "exit: too many arguments\n", GEN_ERR);
		return (false);
	}
	if (right_exitcode(cmd->cmd_args[1], 0, false) == false)
		ft_error(shell, "exit: Numeric argument required\n", 2);
	else
		shell->exit_code = ft_atoi(cmd->cmd_args[1]);
	return (true);
}
