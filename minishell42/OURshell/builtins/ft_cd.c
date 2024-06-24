/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:28:44 by cejin             #+#    #+#             */
/*   Updated: 2024/06/24 15:40:08 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int
	ft_exec_cd(t_shell *shell, t_command *cmd, char *path);

int	ft_cd(t_shell *shell, t_command *cmd)
{
	int			exit_code;

	if (cmd->cmd_args[1] == NULL)
		exit_code = ft_exec_cd(shell, cmd, find_strenv(shell->env, "HOME"));
	else if (cmd->cmd_args[2] == NULL)
		exit_code = ft_exec_cd(shell, cmd, cmd->cmd_args[1]);
	else
		exit_code = ft_error(shell, "cd: Too many arguments\n", GEN_ERR);
	return (exit_code);
}

static int
	ft_exec_cd(t_shell *shell, t_command *cmd, char *path)
{
	DIR	*dir;

	if (path == NULL)
		return (ft_error(shell, "cd: HOME not set\n", GEN_ERR));
	dir = opendir(path);
	if (dir == NULL)
	{
		perror("cd");
		return (ft_error(shell, NULL,
				GEN_ERR));
	}
	closedir(dir);
	chdir(path);
	ft_pwd(shell, cmd, false);
	return (0);
}
