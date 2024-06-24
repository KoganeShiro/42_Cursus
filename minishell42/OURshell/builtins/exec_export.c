/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:31:22 by cejin             #+#    #+#             */
/*   Updated: 2024/06/20 15:48:17 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	fill_key_value(t_shell *shell, t_command *cmd, char **key, char **value)
{
	int			i;
	int			has_a_key;
	static int	j = 1;

	i = 0;
	has_a_key = parse_key(shell, cmd, j);
	if (has_a_key != -1 && has_a_key != 1)
	{
		*key = ft_calloc(ft_strlen(cmd->cmd_args[j]) + 1, sizeof(char));
		while (cmd->cmd_args[j][i] != '+' && cmd->cmd_args[j][i] != '='
			&& cmd->cmd_args[j][i] != '\0')
		{
			(*key)[i] = cmd->cmd_args[j][i];
			i++;
		}
		(*key)[i] = '\0';
		if (cmd->cmd_args[j][i] == '=' || cmd->cmd_args[j][i] == '+')
			fill_value(shell, cmd->cmd_args[j], *key, value);
	}
	j++;
	if (cmd->cmd_args[j] == NULL)
		j = 1;
	return (has_a_key);
}

static char	*_extract_value(char *cmd_arg, char *key, bool *add)
{
	char	*tmp_value;
	int		j;
	int		i;

	tmp_value = ft_calloc(ft_strlen(cmd_arg), sizeof(char));
	*add = 0;
	j = 0;
	i = ft_strlen(key);
	if (cmd_arg[i] == '+')
	{
		*add = 1;
		i++;
	}
	i++;
	while (cmd_arg[i] != '\0')
		tmp_value[j++] = cmd_arg[i++];
	tmp_value[j++] = '\0';
	return (tmp_value);
}

void	fill_value(t_shell *shell, char *arg, char *key, char **value)
{
	char	*tmp_value;
	char	*old_value;
	bool	add;

	old_value = return_value(key, shell->env);
	tmp_value = _extract_value(arg, key, &add);
	*value = tmp_value;
	if (!is_key_existing(key, shell->env))
		shell->create_node = 1;
	else if (is_key_existing(key, shell->env) && !add)
		_fill_value(shell, key, *value);
	else if (is_key_existing(key, shell->env) && add)
	{
		*value = pipex_join(old_value, tmp_value, 0);
		free(tmp_value);
		_fill_value(shell, key, *value);
	}
}

void	_fill_value(t_shell *shell, char *key, char *value)
{
	t_env	*tmp;

	tmp = shell->env;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value;
		}
		tmp = tmp->next;
	}
}
