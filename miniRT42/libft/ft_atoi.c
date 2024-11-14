/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <echapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:45:13 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/30 13:15:01 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr(int signe, int nbr, int moins)
{
	if (signe > 1)
		return (0);
	else if (moins == 1)
		return (-nbr);
	else
		return (nbr);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	moins;
	int	nbr;
	int	signe;

	i = 0;
	moins = 0;
	nbr = 0;
	signe = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			moins++;
		signe++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - 48;
		i++;
	}
	return (ft_nbr(signe, nbr, moins));
}
/*
int    main(void)
{
    char    *str = "   -12345ab567";
    printf("ma fonction:%d\n", ft_atoi(str));
    printf("atoi man:%d", atoi(str));
    return (0);
}*/
