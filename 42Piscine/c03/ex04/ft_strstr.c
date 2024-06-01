/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:00:11 by cejin             #+#    #+#             */
/*   Updated: 2023/07/13 10:15:15 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] && str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int     main(int argc, char **argv)
{
	(void)argc;
        printf("strstr : %s\n", strstr(argv[1], argv[2]));
        printf("ft_strstr : %s\n", ft_strstr(argv[1], argv[2]));
	return (0);
}
*/
