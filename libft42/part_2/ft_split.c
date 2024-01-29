/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:22:55 by cejin             #+#    #+#             */
/*   Updated: 2023/10/27 15:39:30 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int		i;
	int		in_word;
	int		num_words;

	i = 0;
	in_word = 0;
	num_words = 0;
	while (s[i])
	{
		if (!(s[i] == c) && in_word == 0)
		{
			num_words++;
			in_word = 1;
		}
		if ((s[i] == c) && in_word == 1)
			in_word = 0;
		i++;
	}
	return (num_words);
}

static char	*next_word(const char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc((end - start + 1) * (sizeof(char)));
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

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	j;
	size_t	i;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	result = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			result[j++] = next_word(s, start, i);
			start = -1;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}
