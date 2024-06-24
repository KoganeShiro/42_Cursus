/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:04:19 by vharatyk          #+#    #+#             */
/*   Updated: 2024/06/21 12:24:03 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	verif_redirection(t_shell *shell, t_input *input, int *i)
{
	if (input->tab[*i] == '<')
	{
		if (input->tab[++*i] == WORD)
			return (0);
		else
			return (ft_error(shell, "parse error\n", 2));
	}
	else if (input->tab[*i] == '>')
	{
		if (input->tab[++*i] == WORD)
			return (0);
		else
			return (ft_error(shell, "parse error\n", 2));
	}
	return (0);
}

int	verif_herdoc(t_shell *shell, t_input *input, int *i)
{
	if (input->tab[*i] == HEREDOC)
	{
		if (input->tab[++*i] == WORD)
			;
		else
			return (ft_error(shell, "parse error near '<'\n", 2));
	}
	else if (input->tab[*i] == APPEND)
	{
		if (input->tab[++*i] == WORD)
			;
		else
			return (ft_error(shell, "parse error near '>'\n", 2));
	}
	return (0);
}

/*
varfication de pipe
si il y a une pipe on regarde si il y a quelle que chose devent ou dernier
*/
int	verif_pipe(t_shell *shell, t_input *input, int *i)
{
	if (input->tab[*i] == PIPE)
	{
		if (*i == 0)
			return (ft_error(shell, "syntax error near unexpected token '|'\n",
					2));
		if (input->tab[++*i])
			return (10);
		else
			return (ft_error(shell, "syntax error near unexpected token ' '\n",
					2));
	}
	return (0);
}

int	verif_command(t_input *input, t_shell *shell)
{
	int	i;

	i = 0;
	while (input->tab[i])
	{
		if (verif_pipe(shell, input, &i) == 2)
			return (1);
		if (verif_redirection(shell, input, &i) == 2)
			return (1);
		if (verif_herdoc(shell, input, &i) == 2)
			return (1);
		i++;
	}
	return (0);
}
