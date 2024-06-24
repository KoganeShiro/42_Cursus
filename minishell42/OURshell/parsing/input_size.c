/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:15:37 by vharatyk          #+#    #+#             */
/*   Updated: 2024/06/22 18:56:45 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	enumere le nombre element via un system de trigger
*/
void	count_arg(t_input *input, char *s)
{
	if (s[input->i] != ' ' && s[input->i] != '\t' && s[input->i] != '\n'
		&& s[input->i] != '\0' && s[input->i] != '|' && s[input->i] != '<'
		&& s[input->i] != '>' && s[input->i] != '\'' && s[input->i] != '"'
		&& input->trigger == 0)
	{
		input->trigger = 1;
		input->len++;
	}
	else if (s[input->i] == ' ' || s[input->i] == '\t' || s[input->i] == '\n'
		|| s[input->i] == 34 || s[input->i] == 39 || s[input->i] == '|'
		|| s[input->i] == '\0' )
	{
		input->trigger = 0;
	}
}

/*
cont qoate permet de verifier si il y a pas esseur
*/
int	count_quote(t_input *input, char *s, t_shell *info)
{
	int	value;

	value = 0;
	if (s[input->i] == 34 || s[input->i] == 39)
	{
		while (s[input->i] != ' ' && s[input->i] != '\t' && s[input->i] != '\n'
			&& s[input->i] != '\0')
		{
			if (test_quote(info, 34, input, &value) == -1)
				return (-1);
			if (test_quote(info, 39, input, &value) == -1)
				return (-1);
			if (s[input->i] != '\0')
				input->i++;
		}
		if (value == 1)
		{
			input->len++;
			value = 0;
		}
	}
	return (0);
}

int	unexpected_token(char *str, t_input *input, t_shell *shell)
{
	if (str[input->i] == '&' || str[input->i] == '~' || str[input->i]
		== '&' || str[input->i] == ';')
		return (ft_error(shell, "syntax error\n", 2));
	if (str[input->i] == '|')
	{
		if (str[input->i + 1] == '|')
			return (ft_error(shell,
					"syntax error near unexpected token '|'\n", 2));
		input->len++;
	}
	if (str[input->i] == '<' || str[input->i] == '>')
	{
		if (str[input->i + 1] == '<' || str[input->i + 1] == '>')
		{
			if (str[input->i + 2] == '<')
				return (ft_error(shell,
						"syntax error near unexpected token '>'\n", 2));
			if (str[input->i + 2] == '>')
				return (ft_error(shell,
						"syntax error near unexpected token '<'\n", 2));
		}
		else
			input->len++;
	}
	return (0);
}

int	nb_of_words(char *str, t_input *input, t_shell *shell)
{
	input->len = 0;
	input->i = 0 ;
	input->trigger = 0;
	while (str[input->i] != '\0')
	{
		if (count_quote(input, str, shell) != 0)
			return (-1);
		if (unexpected_token(str, input, shell) != 0)
			return (-1);
		count_arg(input, str);
		if (str[input->i] != '\0')
			input->i++;
	}
	return (input->len);
}
