/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:19:10 by cejin             #+#    #+#             */
/*   Updated: 2023/07/20 09:29:48 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcount_strs(int size, char **strs)
{
	int	n;
	int	count;

	n = 0;
	count = 0;
	while (n < size)
	{
		count += ft_strlen(strs[n]);
		n++;
	}
	return (count);
}

char	*ft_strcat(char *result, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(result);
	while (sep[i] != '\0')
	{
		result[len + i] = sep[i];
		i++;
	}
	result[len + i] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		str_len;

	i = 0;
	str_len = ft_strcount_strs(size, strs) + ft_strlen(sep) * (size - 1);
	result = (char *)malloc((str_len + 1) * sizeof(char));
	if (size == 0)
		return (result);
	if (result == 0)
		return (NULL);
	result[0] = 0;
	if (strs[i] == 0)
		return (0);
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
/*
int    main(int argc, char *argv[])
{
    char *dest;

    if (1 < argc)
    {
        dest = ft_strjoin(argc - 2, argv + 2, argv[1]);
        printf("%s\n", dest);
    }
    else
        printf("required 'sep' ...\n");
    return (0);
}*/
