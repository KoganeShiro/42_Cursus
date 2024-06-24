/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:02:06 by vharatyk          #+#    #+#             */
/*   Updated: 2024/06/22 18:58:04 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*append_node(t_env **env, char *line)
{
	int		i;
	int		value_len;
	t_env	*new_node;

	new_node = ft_calloc(1, sizeof(t_env));
	i = 0;
	while (line[i] != '\0' && line[i] != '=')
		i++;
	if (line[i] == '=')
	{
		value_len = ft_strlen(line) - i - 1;
		new_node->key = ft_calloc(i + 1, sizeof(char));
		ft_strlcpy(new_node->key, line, i + 1);
		new_node->value = ft_calloc(value_len + 1, sizeof(char));
		ft_strlcpy(new_node->value, line + i + 1, value_len + 1);
	}
	if (*env != NULL)
	{
		new_node->next = *env;
		*env = new_node;
	}
	else
		*env = new_node;
	return (new_node);
}

t_env	*convert_envp(char **envp)
{
	int		i;
	t_env	*head;
	t_env	*current;

	i = 0;
	if (envp == NULL || envp[0] == NULL)
		return (NULL);
	head = NULL;
	while (envp[i] != NULL)
	{
		if (head == NULL)
		{
			head = append_node(&head, envp[i]);
			current = head;
		}
		else
		{
			current->next = append_node(&(current->next), envp[i]);
			current = current->next;
		}
		i++;
	}
	return (head);
}
