/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:36:45 by cejin             #+#    #+#             */
/*   Updated: 2024/06/19 14:41:48 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free(void *arg, int type)
{
	if (type == 1)
	{
		free((char *)arg);
		arg = NULL;
	}
	else if (type == 2)
	{
		free((t_env *)arg);
		arg = NULL;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		if (tab[i] != NULL)
			ft_free(tab[i], 1);
		i++;
	}
	if (tab != NULL)
		free(tab);
	tab = NULL;
}

void	free_env_node(t_env *env)
{
	if (env->key != NULL)
	{
		free(env->key);
		env->key = NULL;
	}
	if (env->value != NULL)
	{
		free(env->value);
		env->key = NULL;
	}
	if (env != NULL)
	{
		free(env);
		env = NULL;
	}
}

void	free_envp(t_env **env)
{
	t_env	*var_tmp;

	if (*env == NULL)
		return ;
	while (*env != NULL)
	{
		if ((*env)->key != NULL)
			ft_free((*env)->key, 2);
		if ((*env)->value != NULL)
			ft_free((*env)->value, 2);
		var_tmp = (*env);
		(*env) = (*env)->next;
		if (var_tmp != NULL)
			ft_free(var_tmp, 2);
	}
	free(*env);
	env = NULL;
}

int	free_input(t_input *input)
{
	int	i;

	i = 0;
	if (input == NULL)
		return (0);
	if (input->lst == NULL || input->lst[0] == NULL)
		return (0);
	while (input->lst[i] != NULL)
	{
		if (input->lst[i] == NULL)
			continue ;
		free(input->lst[i]);
		i++;
	}
	free(input->lst);
	free(input->tab);
	input->lst = NULL;
	input->tab = NULL;
	return (0);
}
