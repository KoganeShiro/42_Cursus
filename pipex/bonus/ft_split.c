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

#include "pipex_bonus.h"

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(str);
	res = ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	return (res);
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
	int		i;

	i = 0;
	if (!s || s[i] == '\0')
	{
		res = ft_calloc(2, sizeof(char *));
		if (res == NULL)
			return (NULL);
		res[i] = ft_strdup("cmd_not");
		res[i + 1] = NULL;
		return (res);
	}
	else
	{
		res = ft_calloc(word_count(s, sep) + 1, sizeof(char *));
		if (res == NULL)
			return (NULL);
		fill_result(res, s, sep);
	}
	return (res);
}

/*
int	main(int argc, char **argv, char **envp)
{
	char	**cmd;
	char	**cmd2;

	cmd = ft_split((const char *)argv[1], " ");
	cmd2 = ft_split((const char *)argv[2], " ");
	for (int i = 0; cmd[i] != NULL || cmd2[i] != NULL; i++) {
		printf("split: %s\n", cmd[i]);
		printf("split: %s\n", cmd2[i]);
	}
	printf("\n");
}
*/
