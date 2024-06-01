/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:54:49 by cejin             #+#    #+#             */
/*   Updated: 2023/07/12 09:22:28 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_strlowcase(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] >= 'A' && str[c] <= 'Z')
		{
			str[c] += 32;
		}
		c++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			&& !((str[i - 1] >= 'a' && str[i - 1] <= 'z')
				|| (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
				|| (str[i - 1] >= '0' && str[i - 1] <= '9')))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
char	*ft_strcapitalize(char *str);
int		main(void)
{
	char	str[] = "salut, comment tu vas ? 42mots quaRAnte-deux; cinquante+et+un";
	printf("%s", ft_strcapitalize(str));
}
*/
