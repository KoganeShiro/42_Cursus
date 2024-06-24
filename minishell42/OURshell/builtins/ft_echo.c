/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:30:51 by cejin             #+#    #+#             */
/*   Updated: 2024/06/23 17:45:29 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_newline(char **argv, int j);

int	ft_strncmp_echo(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
	{
		i++;
		n--;
	}
	return (s1[i] - s2[i]);
}

int	ft_echo(int argc, char **argv, int newline)
{
	int		j;

	j = 1;
	argc = ft_tab_len(argv);
	newline = 1;
	while (argc > 1 && ft_strncmp_echo(argv[j], "-n", 2) == 0)
	{
		if (ft_newline(argv, j) == 0)
			break ;
		newline = 0;
		j++;
	}
	if (argv[j] == NULL)
		return (0);
	while (argv[j] != NULL)
	{
		write(1, argv[j], ft_strlen(argv[j]));
		j++;
		if (argv[j] != NULL)
			write(1, " ", 1);
	}
	if (newline == 1)
		write(1, "\n", 1);
	return (0);
}

static int	ft_newline(char **argv, int j)
{
	int	i;

	i = 1;
	while (argv[j][i] != '\0')
	{
		if (argv[j][i] != 'n')
			return (0);
		i++;
	}
	return (1);
}
