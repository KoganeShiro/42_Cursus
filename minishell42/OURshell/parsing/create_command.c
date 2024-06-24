/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:09:36 by vharatyk          #+#    #+#             */
/*   Updated: 2024/06/22 13:55:11 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	_fill_linked_list(t_shell *shell, t_input *input)
{
	t_command	*new_cmd;
	t_command	*current;
	int			i;

	i = 0;
	while (input->tab[i] != 0)
	{
		if (input->tab[i] == PIPE)
		{
			i++;
			new_cmd = init_node(shell, i);
			current = new_cmd;
		}
		i++;
	}
}

int	create_command(t_shell *shell, t_input *input)
{
	t_command	*new_cmd;
	t_command	*current;

	if (verif_command(input, shell) == 1)
	{
		free_input(input);
		free_input(shell->input);
		return (1);
	}
	new_cmd = init_first_node(shell, input);
	if (new_cmd == NULL)
		return (1);
	current = new_cmd;
	_fill_linked_list(shell, input);
	current = shell->cmd;
	while (current->next != NULL)
		current = current->next;
	current->last_node = 1;
	return (0);
}

t_command	*init_first_node(t_shell *shell, t_input *input)
{
	t_command	*new_cmd;

	new_cmd = ft_calloc(1, sizeof(t_command));
	init_command(new_cmd);
	new_cmd->cmd_args = ft_calloc(input->len + 1, sizeof(char *));
	shell->nb_of_node = 1;
	new_cmd->first_node = 1;
	if (init_cmd(input, new_cmd, 0) == 1)
		shell->nb_of_cmd = 1;
	else
		shell->nb_of_cmd = 0;
	new_cmd->next = NULL;
	shell->nb_of_node = 1;
	shell->cmd = new_cmd;
	return (new_cmd);
}

t_command	*init_node(t_shell *shell, int i)
{
	t_command	*new_cmd;
	t_command	*current;

	new_cmd = ft_calloc(1, sizeof(t_command));
	init_command(new_cmd);
	new_cmd->cmd_args = ft_calloc(shell->input->len + 1, sizeof(char *));
	if (init_cmd(shell->input, new_cmd, i) == 1)
		shell->nb_of_cmd++;
	shell->nb_of_node++;
	current = shell->cmd;
	while (current->next != NULL)
		current = current->next;
	current->next = new_cmd;
	new_cmd->next = NULL;
	return (new_cmd);
}

int	init_cmd(t_input *input, t_command *new_cmd, int i)
{
	int	j;

	j = 0;
	while (input->tab[i] != 0 && input->tab[i] != PIPE)
	{
		if (input->tab[i] == INREDIR || input->tab[i] == OUTREDIR
			|| input->tab[i] == APPEND || input->tab[i] == HEREDOC)
			i += 2;
		if (input->tab[i] == WORD)
		{
			new_cmd->cmd_args[j] = input->lst[i];
			j++;
			i++;
		}
	}
	new_cmd->cmd_args[j] = NULL;
	if (j > 0)
		return (1);
	return (0);
}
