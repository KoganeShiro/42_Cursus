/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:33:24 by vharatyk          #+#    #+#             */
/*   Updated: 2024/06/23 14:34:34 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
name : void	remove_var(t_input *input, int start)
note : peremt de retier un variable si elle nexsite pas.
*/
void	remove_var(t_input *input, int start)
{
	int		i;
	int		j;
	char	*nstr;

	i = -1;
	if (input == NULL || input->str == NULL)
		return ;
	nstr = ft_calloc(ft_strlen(input->str) + 5, sizeof(char));
	while (++i < start)
		nstr[i] = input->str[i];
	j = i;
	if (input->str[start] == '$')
		i++;
	while (input->str[i])
	{
		if (ft_isalpha_num(input->str[i]))
			i++;
		else
			break ;
	}
	while (input->str[i])
		nstr[j++] = input->str[i++];
	nstr[j] = '\0';
	free(input->str);
	input->str = nstr;
}

/*
name :
note : tant que elements est dans un quote elle se fait copier
*/
char	*is_this_a_quote(t_input *input, char quote, int *p, char *new_word)
{
	if (input->lst[input->j][input->i] == quote)
	{
		input->i++;
		while (input->lst[input->j][input->i] != quote &&
				input->lst[input->j][input->i])
		{
			new_word[*p] = input->lst[input->j][input->i];
			input->i++;
			(*p)++;
		}
	}
	return (new_word);
}

void	remove_quote(t_input *input)
{
	char	*new_word;
	int		p;

	input->j = 0;
	while (input->lst[input->j] != NULL)
	{
		p = 0;
		input->i = 0;
		input->trigger = 0 ;
		new_word = ft_calloc(ft_strlen(input->lst[input->j]) + 3, sizeof(char));
		while (input->lst[input->j][input->i])
		{
			new_word = is_this_a_quote(input, '"', &p, new_word);
			new_word = is_this_a_quote(input, '\'', &p, new_word);
			if (input->lst[input->j][input->i] != '\'' &&
				input->lst[input->j][input->i] != '"')
				new_word[p++] = input->lst[input->j][input->i];
			input->i++;
		}
		new_word[p] = '\0';
		free(input->lst[input->j]);
		input->lst[input->j] = new_word;
		input->j++;
	}
	input->lst[input->j] = NULL;
}

int	parsing(t_shell *shell, t_input *input)
{
	if (input->str == NULL)
		return (0);
	input->i = 0;
	if (replace_envp(input, shell))
	{
		shell->status = shell->exit_code;
		return (1);
	}
	if (ft_split_input(input->str, input, shell))
	{
		shell->status = shell->exit_code;
		return (1);
	}
	remove_quote(input);
	shell->input = input;
	if (create_command(shell, input) == 1)
	{
		shell->status = shell->exit_code;
		return (1);
	}
	return (0);
}
