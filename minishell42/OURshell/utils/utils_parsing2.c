/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:53:16 by vharatyk          #+#    #+#             */
/*   Updated: 2024/06/23 14:35:14 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	remplace_word(t_input *input, char *value, char **nword, int i)
{
	while (value[input->value_i] != '\0')
	{
		if (input->trigger == 0)
		{
			i = no_name_condition(input, value, nword, i);
		}
		if (value[input->value_i] == '\0')
			break ;
		(*nword)[i++] = value[input->value_i++];
	}
	return (i);
}

int	no_name_condition(t_input *input, char *value, char **nword, int i)
{
	if (value[input->value_i] == '|')
		i = remplace_special_and_char(input, "|", nword, i);
	else if (value[input->value_i] == '<'
		&& value[input->value_i + 1] == '<')
	{
		i = remplace_special_and_char(input, "<<", nword, i);
		input->value_i++;
	}
	else if (value[input->value_i] == '>'
		&& value[input->value_i + 1] == '>')
	{
		i = remplace_special_and_char(input, ">>", nword, i);
		input->value_i++;
	}
	else if (value[input->value_i] == '>')
		i = remplace_special_and_char(input, ">", nword, i);
	else if (value[input->value_i] == '<')
		i = remplace_special_and_char(input, "<", nword, i);
	return (i);
}

char	*fill_input_key(t_input *input)
{
	char	*in_str;
	int		j;
	int		i;

	j = 0;
	i = input->i + 1;
	in_str = ft_calloc(ft_strlen(input->str) + 1, sizeof(char));
	while (input->str[i] != '\0' && input->str[i] != ' '
		&& input->str[i] != '\t' && input->str[i] != '$'
		&& input->str[i] != '\'' && input->str[i] != '"'
		&& input->str[i] != '/')
	{
		in_str[j] = input->str[i];
		j++;
		i++;
	}
	in_str[j] = '\0';
	return (in_str);
}

int	print_dellard(t_input *in)
{
	return (in->str[in->i + 1] == ' '
		|| in->str[in->i + 1] == '\0'
		|| in->str[in->i + 1] == '"'
		|| in->str[in->i + 1] == '\''
		|| in->str[in->i + 1] == '/'
		|| in->str[in->i + 1] == '\\');
}
