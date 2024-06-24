/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:27:36 by vharatyk          #+#    #+#             */
/*   Updated: 2024/06/23 14:34:19 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
name : char	*add_char(int debut, int taille du carathere a remplacer,
		char * env, char *str)
note : ajoute a la ligne un mots
*/
int	add_int(int start, int len, char *word, t_input *input)
{
	int		i;
	int		j;
	int		prev;
	char	*ninput;

	ninput = ft_calloc(ft_strlen(input->str)
			+ ft_strlen(word) + 1 - len, sizeof(char));
	i = 0;
	while (i < start)
	{
		ninput[i] = input->str[i];
		i++;
	}
	j = 0;
	prev = i ;
	while (word[j] != '\0')
		ninput[i++] = word[j++];
	while (input->str[prev + len] != '\0')
		ninput[i++] = input->str[prev++ + len];
	ninput[i] = '\0';
	free(input->str);
	free(word);
	input->str = ninput;
	return (0);
}

/*
name :int	verif_env_valid(t_input *input, int *ti ,char *str , t_env *tmp_env)
note : permet de verifier si le $VAR correspond a une des variable ENV.
*/

int	verif_env_valid(t_input *input, t_env *tmp_env, int *i)
{
	int		x;
	char	*in_str;

	*i = input->i + 1;
	in_str = fill_input_key(input);
	x = 0;
	while (ft_isalpha_num(input->str[*i]) && input->str[*i] != '\0')
	{
		if (ft_strcmp(tmp_env->key, in_str) == 0)
		{
			(*i)++;
			if (tmp_env->key[x])
				x++;
		}
		else
		{
			break ;
		}
	}
	free(in_str);
	return (x);
}

/*
name : int	compare_envp(t_input *input, t_shell *shell ,char *str)
note : verifiacation que la variabel existe , si elle exite
		ou la remplace sinon on la delete.
*/
int	compare_envp(t_input *input, t_shell *shell, char *str)
{
	int		x;
	int		i;
	t_env	*tmp_env;

	i = 0;
	tmp_env = shell->env;
	while (tmp_env != NULL)
	{
		x = verif_env_valid(input, tmp_env, &i);
		if (!ft_isalpha_num(str[i]) || str[i] == '\0')
		{
			if (tmp_env->key[x] == '\0')
			{
				return (add_var_line(input->i, input, tmp_env, shell));
			}
			else
				remove_var(input, input->i);
			input->i = 0;
			return (1);
		}
		else
			tmp_env = tmp_env->next;
	}
	remove_var(input, input->i);
	return (input->i + 1);
}

/*
name : void	quote_is(t_input *input)
note : avance rapid si il ya  des guimmets ' '
*/
int	quote_is(t_input *input)
{
	if (input->str[input->i] == '"')
	{
		if (input->trigger == 0)
			input->trigger = 1;
		else if (input->trigger == 1)
			input->trigger = 0;
	}
	else if (input->str[input->i] == '\'' && input->trigger == 0)
	{
		input->i++;
		while (input->str[input->i] != '\'' && input->str[input->i])
			input->i++;
		if (input->str[input->i] == '\0')
			return (1);
	}
	return (0);
}

/*
name : int	replace_envp(t_input *input, t_shell *shell)
note : veirifie si il y a sur la ligne des variable , remplace ou suprimme.
*/
int	replace_envp(t_input *in, t_shell *shell)
{
	in->trigger = 0 ;
	while (in->str[in->i])
	{
		if (quote_is(in) == 1)
			break ;
		if (in->str[in->i] == '$')
		{
			if (print_dellard(in))
				in->i++;
			else if (in->str[in->i + 1] == '$')
				add_int(in->i, 2, ft_itoa(shell->pid), in);
			else if (in->str[in->i + 1] == '?')
				add_int(in->i, 2, ft_itoa(shell->status), in);
			else if (in->str[in->i + 1])
			{
				compare_envp(in, shell, in->str);
			}
			else
				in->i++;
		}
		else
			in->i++;
	}
	return (0);
}
