/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:36:48 by cejin             #+#    #+#             */
/*   Updated: 2024/06/20 15:11:28 by cejin            ###   ########.fr       */
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

int	ft_tab_len(char **tab)
{
	int	i;

	i = 0;
	if (tab[i] == NULL || tab[i][0] == '\0')
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

char	*find_strenv(t_env *env, char *key)
{
	t_env	*cur;

	cur = env;
	while (env != NULL)
	{
		if (cur == NULL || cur->key == NULL)
			return (NULL);
		if (ft_strcmp(cur->key, key) == 0)
			return (cur->value);
		cur = cur->next;
	}
	return (NULL);
}

char	*return_value(char *key, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

bool	is_key_existing(char *key, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	create_node(t_shell *shell, char *key, char *value)
{
	t_env	*new_node;
	t_env	*tmp;

	new_node = (t_env *)malloc(sizeof(t_env));
	tmp = shell->env;
	shell->create_node = 0;
	new_node->key = ft_strdup(key);
	new_node->value = value;
	new_node->next = NULL;
	if (tmp == NULL)
	{
		shell->env = new_node;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
}
