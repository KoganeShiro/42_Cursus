/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:58:35 by vharatyk          #+#    #+#             */
/*   Updated: 2024/06/23 13:24:13 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	verif_special(char *str, t_shell *info)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '>' || str[i] == '<' )
// 		{
// 			if (str[i] == '>')
// 				return (ft_error(info, ">>: unary operator expected\n"
// 						, 2));
// 			else if (str[i] == '<')
// 				return (ft_error(info, "<<: unary operator expected\n"
// 						, 2));
// 			else if (str[i-1] == '\'' && str[i] == '|' && str[i+1] == '\'' )
// 				{}
// 		} $test = salut | coucou
// 		else
// 			i++;
// 	}
// 	return (0);
// }

/*
une fois le debut de la ligne copier on vient coller le value et
la fin de la ligne
*/
int	add_line_var(t_input *input, t_env *env, int start)
{
	char	*nword;
	int		tmp;
	int		i;

	nword = ft_calloc((ft_strlen(input->str)
				+ ft_strlen(env->value)) * 2, sizeof(char));
	i = 0;
	while (i < start)
	{
		nword[i] = input->str[i];
		i++;
	}
	i = remplace_word(input, env->value, &nword, i) - 1;
	tmp = 0;
	while ((input->str[start + ft_strlen(env->key) + tmp]) != '\0')
	{
		nword[++i] = input->str[start + ft_strlen(env->key) + 1 + tmp];
		tmp++;
	}
	nword[i] = '\0';
	free(input->str);
	input->str = nword;
	return (0);
}

int	remplace_special_and_char(t_input *input, char *value, char **nword, int i )
{
	int	y;

	y = 0;
	(*nword)[i++] = '"';
	while (value[y])
		(*nword)[i++] = value[y++];
	(*nword)[i++] = '"';
	input->value_i++;
	return (i);
}

/*
add la varible enviroment a la ligne
*/
int	add_var_line(int start, t_input *input, t_env *env, t_shell *shell)
{
	(void)shell;
	input->value_i = 0;
	add_line_var(input, env, start);
	return (0);
}

int	ft_isalpha_num(int c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9')
		|| c == '_');
}
