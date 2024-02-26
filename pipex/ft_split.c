/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:06:09 by cejin             #+#    #+#             */
/*   Updated: 2024/02/21 14:07:05 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*src;

	src = (char *)s;
	i = 0;
	while (n != 0)
	{
		src[i] = 0;
		i++;
		n--;
	}
	return ;
}

int	word_count(char const *s, const char *sep)
{
	int		i;
	int		in_word;
	int		num_words;

	i = 0;
	in_word = 0;
	num_words = 0;
	while (s[i])
	{
		if (!ft_strchr(sep, s[i]) && in_word == 0)
		{
			num_words++;
			in_word = 1;
		}
		if (ft_strchr(sep, s[i]) && in_word == 1)
			in_word = 0;
		i++;
	}
	return (num_words);
}

char	*next_word(const char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = ft_calloc((end - start + 1), sizeof(char));
	if (word == NULL)
		return (0);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

void	fill_result(char **result, const char *s, const char *sep)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = -1;
	while (s[i])
	{
		if (!ft_strchr(sep, s[i]))
		{
			if (start < 0)
				start = i;
		}
		else if (start >= 0)
		{
			result[j++] = next_word(s, start, i);
			start = -1;
		}
		i++;
	}
	if (start >= 0)
		result[j++] = next_word(s, start, i);
}

char	**ft_split(char const *s, const char *sep)
{
	char	**res;

	res = ft_calloc(word_count(s, sep) + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	fill_result(res, s, sep);
	return (res);
}

/*
int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	**path;

	i = 0;
	printf("\n");
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=/", 5) == 0)
		{
			printf("envp %s\n", envp[i] + 6);
			path = ft_split(envp[i] + 6, ":");
			i = 0;
			printf("path %s\n", path[i]);
			//check where is the cmd
			//give it to execve
			break ;
		}
		i++;
	}
	printf("\n");
}
*/
