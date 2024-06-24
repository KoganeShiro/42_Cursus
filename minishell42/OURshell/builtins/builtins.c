/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:13:55 by cejin             #+#    #+#             */
/*   Updated: 2024/06/19 13:09:35 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 *Your shell must implement the following builtins:
	◦- `echo` with option -n
	◦+ `cd` with only a relative or absolute path
	◦- `pwd` with no options
	◦~ `export` with no options
	◦- `unset` with no options
	◦-`env` with no options or arguments
	◦ `exit` with no options
*/

/*
	return (0) --> no builtins
	return (1) --> exec in parent
	return (2) --> exec in child
*/

int	is_builtins(t_command *cmd)
{
	if (ft_strcmp(cmd->cmd_args[0], "echo") == 0)
		return (2);
	else if (ft_strcmp(cmd->cmd_args[0], "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd->cmd_args[0], "pwd") == 0)
		return (2);
	else if (ft_strcmp(cmd->cmd_args[0], "export") == 0)
		return (1);
	else if (ft_strcmp(cmd->cmd_args[0], "unset") == 0)
		return (1);
	else if (ft_strcmp(cmd->cmd_args[0], "env") == 0)
		return (2);
	else if (ft_strcmp(cmd->cmd_args[0], "exit") == 0)
		return (1);
	else
		return (-1);
}

bool	handle_builtins(t_shell *shell, t_command *cmd)
{
	int	argc;
	int	nl;

	argc = 0;
	nl = 0;
	if (ft_strcmp(cmd->cmd_args[0], "echo") == 0)
		shell->exit_code = ft_echo(argc, cmd->cmd_args, nl);
	else if (ft_strcmp(cmd->cmd_args[0], "cd") == 0)
		shell->exit_code = ft_cd(shell, cmd);
	else if (ft_strcmp(cmd->cmd_args[0], "pwd") == 0)
		shell->exit_code = ft_pwd(shell, cmd, true);
	else if (ft_strcmp(cmd->cmd_args[0], "export") == 0)
		shell->exit_code = ft_export(shell, cmd);
	else if (ft_strcmp(cmd->cmd_args[0], "unset") == 0)
		shell->exit_code = ft_unset(shell, cmd, shell->env);
	else if (ft_strcmp(cmd->cmd_args[0], "env") == 0)
		shell->exit_code = ft_env(shell, cmd);
	else if (ft_strcmp(cmd->cmd_args[0], "exit") == 0)
		ft_exit(shell, cmd, true);
	else
		return (false);
	return (true);
}
