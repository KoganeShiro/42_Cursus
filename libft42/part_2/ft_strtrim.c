/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:13:33 by cejin             #+#    #+#             */
/*   Updated: 2023/10/23 18:49:01 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	int		start;
	int		end;

	if (s1 == NULL || set == NULL)
		return (0);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	trimmed_str = ft_substr(s1, start, end - start + 1);
	return (trimmed_str);
}
/*
#include <stdio.h>

int	main()
{
	char	s1[] = "kaykak";
	char	set[] = "yak";
	
	printf("ft_strtrim; %s\n", ft_strtrim(s1, set));
	return (0);
}
*/