/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:33:17 by cejin             #+#    #+#             */
/*   Updated: 2023/07/26 14:31:27 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_strncpy(char *dest, char *src, int count)
{
	int	i;

	i = 0;
	while (src[i] && count > i)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	is_sep(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	strs_len(char *str, char *charset)
{
	int	count;

	count = 0;
	while (str[count] && (!is_sep(charset, str[count])))
		count++;
	return (count);
}

int	count_strs(char *str, char *charset)
{
	int	i;
	int	strs_count;

	i = 0;
	strs_count = 0;
	while (str[i])
	{
		if ((!is_sep(charset, str[i])) && (is_sep(charset, str[i + 1])))
			strs_count++;
		i++;
	}
	return (strs_count);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;
	int		count;

	i = -1;
	j = 0;
	result = (char **)malloc(count_strs(str, charset) * sizeof(char));
	if (result[i] == NULL)
		return (result);
	while (str[++i])
	{
		if (!is_sep(charset, str[i]))
		{
			count = strs_len(&str[i], charset);
			result[j] = (char *)malloc((count + 1) * sizeof(char));
			if (result[j] == NULL)
				return (result);
			ft_strncpy(result[j++], &str[i], count);
			i += count - 1;
		}
	}
	result[j] = NULL;
	return (result);
}
/*
#include <stdio.h>

int    main(int argc, char *argv[])
{
    char    **split;

    if (2 < argc)
    {
        split = ft_split(argv[1], argv[2]);
        while (*split)
            printf("%s\n", *(split++));
    }
    else
        printf("required 'str' 'charset'\n");
}*/
