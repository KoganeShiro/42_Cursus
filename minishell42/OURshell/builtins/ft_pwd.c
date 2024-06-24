/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:31:39 by cejin             #+#    #+#             */
/*   Updated: 2024/06/20 15:24:55 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(t_shell *shell, t_command *cmd, bool print)
{
	char	*buffer;
	int		buffer_size;

	buffer_size = 100;
	buffer = ft_calloc(buffer_size, sizeof(char));
	while (1)
	{
		if (getcwd(buffer, buffer_size) != NULL)
		{
			if (print == true)
				ft_putstr_fd(1, buffer);
			if (print == true)
				write(1, "\n", 1);
			else
				replace_pwd(shell->env, buffer, find_strenv(shell->env, "PWD"));
			free(buffer);
			return (0);
		}
		free(buffer);
		buffer_size = buffer_size * 2;
		buffer = ft_calloc(buffer_size, sizeof(char));
	}
	ft_error(shell, "pwd not found\n", BUILTIN_KO);
	free_child(shell, cmd);
	return (shell->exit_code);
}

void	replace_pwd(t_env *env, char *new_pwd, char *pwd)
{
	t_env		*tmp;
	static char	*old_pwd = NULL;

	tmp = env;
	old_pwd = ft_strdup(pwd);
	if (pwd == NULL || old_pwd == NULL)
		return ;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, "PWD") == 0)
		{
			free(tmp->value);
			tmp->value = ft_strdup(new_pwd);
		}
		if (ft_strcmp(tmp->key, "OLDPWD") == 0)
		{
			free(tmp->value);
			tmp->value = old_pwd;
		}
		tmp = tmp->next;
	}
}
