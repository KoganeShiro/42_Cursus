/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:22:55 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 17:53:42 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(str);
	res = ft_calloc((len + 1), sizeof(char));
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	word_count(char const *s, char space)
{
	int		i;
	int		in_word;
	int		num_words;

	i = 0;
	in_word = 0;
	num_words = 0;
	while (s[i])
	{
		if (!(s[i] == space) && in_word == 0)
		{
			num_words++;
			in_word = 1;
		}
		if ((s[i] == space) && in_word == 1)
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

void	fill_result(char **result, const char *s, char space)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = -1;
	while (s[i])
	{
		if (s[i] != space)
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

char	**ft_split(char const *s, char space)
{
	char	**res;

	res = ft_calloc(word_count(s, space) + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	fill_result(res, s, space);
	return (res);
}
