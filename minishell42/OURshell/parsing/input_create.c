/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:39:26 by cejin             #+#    #+#             */
/*   Updated: 2024/04/23 11:06:37 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
repere le mots sa taille et le creer via created_word
*/
void	add_word(t_input *in, char *str)
{
	if (ft_is_seperator(str[in->i]) && in->index < 0)
		in->index = in->i;
	else if ((str[in->i] == ' ' || str[in->i] == '\t' || str[in->i] == '\n'
			|| str[in->i] == '|' || str[in->i] == '>' || str[in->i] == '<'
			|| in->i == ft_strlen(str)) && in->index >= 0)
	{
		in->tab[in->j] = WORD;
		in->lst[in->j++] = created_word(str, in->index, in->i - 1);
		in->index = -1;
	}
}

/*
si il y a un mots entre guillemnts cette foncions le cree
*/
void	add_quote(t_input *in, char *str)
{
	if (str[in->i] == '\'' || str[in->i] == '"')
	{
		while (ft_is_seperator(str[in->i]))
		{
			pass_quote(in, str);
		}
		in->tab[in->j] = WORD;
		in->lst[in->j++] = created_word(str, in->index, in->i - 1);
		in->index = -1;
	}
}

void	add_unexpected(t_input *in, char *s)
{
	if (s[in->i] == '<' && s[in->i + 1] == '<')
	{
		in->tab[in->j] = HEREDOC ;
		in->lst[in->j] = created_word(s, in->i, in->i + 1);
		in->j++;
		in->i += 1;
	}
	else if (s[in->i] == '>' && s[in->i + 1] == '>')
	{
		in->tab[in->j] = APPEND ;
		in->lst[in->j] = created_word(s, in->i, in->i + 1);
		in->j++;
		in->i += 1;
	}
	else
		add_unexpected_extra(in, s);
}

void	add_unexpected_extra(t_input *in, char *s)
{
	if (s[in->i] == '|')
	{
		in->tab[in->j] = PIPE;
		in->lst[in->j] = created_word(s, in->i, in->i);
		in->j++;
	}
	else if (s[in->i] == '<')
	{
		in->tab[in->j] = INREDIR ;
		in->lst[in->j] = created_word(s, in->i, in->i);
		in->j++;
	}
	else if (s[in->i] == '>')
	{
		in->tab[in->j] = OUTREDIR ;
		in->lst[in->j] = created_word(s, in->i, in->i);
		in->j++;
	}
}

/*
1 . sconnaitre le nombre elements pour correcemnt alloc
2 . malloc tab et lst
3 . ajoute
*/
int	ft_split_input(char *s, t_input *in, t_shell *shell)
{
	if (nb_of_words(s, in, shell) > 0)
	{
		in->j = 0;
		in->i = 0 ;
		in->index = -1;
		in->tab = ft_calloc((in->len + 10), sizeof(int));
		in->lst = ft_calloc((in->len + 10), sizeof(char *));
		if (!s || !in->lst)
			return (1);
		while (in->i <= ft_strlen(s))
		{
			add_word(in, s);
			add_quote(in, s);
			add_unexpected(in, s);
			in->i++;
		}
		in->j++;
		in->lst[in->j] = NULL;
		in->tab[in->j] = 0;
	}
	else
		return (1);
	return (0);
}
