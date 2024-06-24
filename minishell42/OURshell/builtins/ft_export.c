/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:32:49 by cejin             #+#    #+#             */
/*   Updated: 2024/06/23 15:11:41 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#define EXPORT_MSG "Usage: export key='value'\n\
			For more information check the man 📕️\n"

void	_export(t_shell *shell, char *key, char *value)
{
	if (key == NULL)
		ft_error(shell, "export: not a valid identifier\n", 1);
	else if (key != NULL || key[0] != '\0')
	{
		if (value == NULL)
			value = ft_strdup("");
		if (shell->create_node == 1)
			create_node(shell, key, value);
	}
}

int	ft_export(t_shell *shell, t_command	*cmd)
{
	char		*key;
	char		*value;
	int			i;

	i = 1;
	if (cmd->cmd_args[1] == NULL)
	{
		ft_putstr_fd(1, EXPORT_MSG);
		return (0);
	}
	while (cmd->cmd_args[i] != NULL)
		i++;
	i--;
	while (i > 0)
	{
		key = NULL;
		value = NULL;
		if (fill_key_value(shell, cmd, &key, &value) != 1)
			_export(shell, key, value);
		if (key != NULL)
			free(key);
		i--;
	}
	return (shell->exit_code);
}

int	check_key(char *arg, int i)
{
	if (arg[i] == '=')
		return ('=');
	if (arg[i] == '+' && arg[i + 1] == '=')
		return ('+');
	else if (arg[i] == '+' && arg[i + 1] != '=')
		return (-1);
	if ((arg[0] >= '0' && arg[0] <= '9'))
		return (-1);
	if ((arg[i] >= '!' && arg[i] <= '*'))
		return (-1);
	if ((arg[i] >= ',' && arg[i] <= '/'))
		return (-1);
	if ((arg[i] >= '[' && arg[i] <= '^') || arg[i] == '`')
		return (-1);
	if ((arg[i] >= '{' && arg[i] <= '~'))
		return (-1);
	if ((arg[i] == ':' || arg[i] == ';'
			|| arg[i] == '?' || arg[i] == '@'
			|| arg[i] == ' '))
	{
		return (-1);
	}
	return (0);
}

int	_parse_key_loop(char *cmd, int i, int *plus_flag, int *equal_flag)
{
	int	what_char;

	while (cmd[i] != '\0')
	{
		what_char = check_key(cmd, i);
		if (what_char == '+')
		{
			if (*plus_flag == 1)
				return (-1);
			*plus_flag = 1;
		}
		else if (what_char == -1 || cmd[0] == '=')
			return (-1);
		else if (what_char == '=')
		{
			*equal_flag = 1;
			break ;
		}
		i++;
	}
	return (i);
}

int	parse_key(t_shell *shell, t_command *cmd, int j)
{
	int	i;
	int	plus_flag;
	int	equal_flag;

	equal_flag = 0;
	plus_flag = 0;
	i = 0;
	if (cmd->cmd_args[j][0] == '-')
		return (ft_error(shell, "export: -: invalid option\n", 2));
	i = _parse_key_loop(cmd->cmd_args[j], i, &plus_flag, &equal_flag);
	if (i == 0 || i == -1)
		return (-1);
	if (equal_flag == 0)
		return (1);
	return (0);
}
