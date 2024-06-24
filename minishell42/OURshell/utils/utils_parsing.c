/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:58:32 by vharatyk          #+#    #+#             */
/*   Updated: 2024/06/20 11:42:25 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*created_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(((end - start) + 5), sizeof(char));
	while (start <= end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

int	test_quote(t_shell *shell, char c, t_input *input, int *value)
{
	if (input->str[input->i] == c)
	{
		input->i++;
		while (input->str[input->i] != c && input->str[input->i])
			input->i++;
		if (input->str[input->i] == c)
		{
			*value = 1;
		}
		else
		{
			ft_error(shell, "Synthax Error: Unclosed quote\n", 2);
			return (-1);
		}
	}
	return (0);
}

int	pass_quote(t_input *input, char *str)
{
	if (str[input->i] == '\'')
	{
		input->i++;
		if (input->index == -1)
			input->index = input->i;
		while (str[input->i] != '\'' && str[input->i])
			input->i++;
		input->i++;
	}
	else if (str[input->i] == '"')
	{
		input->i++;
		if (input->index == -1)
			input->index = input->i++;
		while (str[input->i] != '"' && str[input->i])
		{
			input->i++;
		}
		input->i++;
	}
	else
		input->i++;
	return (0);
}

int	ft_is_seperator(char c)
{
	return (c != ' ' && c != '\t' && c != '\n' && c != '\0'
		&& c != '<' && c != '>' && c != '|');
}
