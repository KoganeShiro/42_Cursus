/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:05:08 by cejin             #+#    #+#             */
/*   Updated: 2024/06/23 17:43:46 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	list_size(t_env *envp)
{
	int		len;
	t_env	*tmp;

	len = 0;
	tmp = envp;
	if (tmp == NULL)
		return (0);
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

char	**env_to_tab(t_env *envp)
{
	int		i;
	int		len;
	t_env	*tmp;
	char	**env;

	i = 0;
	len = list_size(envp);
	tmp = envp;
	env = ft_calloc(len + 1, sizeof(char *));
	if (env == NULL || tmp == NULL)
	{
		env = NULL;
		return (env);
	}
	while (tmp != NULL)
	{
		env[i] = pipex_join(tmp->key, tmp->value, '=');
		tmp = tmp->next;
		i++;
	}
	env[i] = NULL;
	return (env);
}

int	get_path(t_shell *shell)
{
	t_env		*tmp_env;

	tmp_env = shell->env;
	shell->all_paths = NULL;
	if (tmp_env != NULL)
	{
		while (tmp_env != NULL)
		{
			if (ft_strcmp(tmp_env->key, "PATH") == 0)
			{
				shell->all_paths = ft_split(tmp_env->value, ":");
				break ;
			}
			tmp_env = tmp_env->next;
		}
	}
	tmp_env = shell->env;
	if (shell->all_paths == NULL || tmp_env == NULL)
		return (GEN_ERR);
	return (SUCCESS);
}

void	_pwd_as_path(t_command	*pipex)
{
	char	*buffer;

	pipex->cmd_is_path = 1;
	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	getcwd(buffer, BUFFER_SIZE);
	pipex->cmd_path = pipex_join(buffer, pipex->cmd_args[0], '/');
	free(buffer);
}

int	check_cmd(t_shell *shell, t_command	*pipex)
{
	int		i;

	i = ft_strlen(pipex->cmd_args[0]);
	if (i == -1)
		return (-1);
	while (i >= 0)
	{
		if (ft_strncmp(&pipex->cmd_args[0][i], "/", 1) == 0)
		{
			pipex->cmd_path = strdup(pipex->cmd_args[0]);
			pipex->cmd_args[0] = pipex->cmd_path + (i + 1);
			pipex->cmd_is_path = 1;
			break ;
		}
		i--;
	}
	if (shell->all_paths == NULL && pipex->cmd_is_path != 1)
		_pwd_as_path(pipex);
	return (shell->exit_code);
}
