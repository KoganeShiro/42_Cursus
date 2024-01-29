/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:11:58 by cejin             #+#    #+#             */
/*   Updated: 2023/10/23 12:04:47 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	total_len;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((total_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_bzero(result, total_len + 1);
	ft_strlcat(result, s1, total_len + 1);
	ft_strlcat(result, s2, total_len + 1);
	return (result);
}
/*
#include <stdio.h>

int main()
{
    char s1[40] = "lorem ipsumdolor";
    char s2[40] = " sit amet";
    printf("ft_strjoin %s\n", ft_strjoin(s1, s2));
}
*/