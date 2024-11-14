/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:37:53 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/31 14:03:02 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_tab(int len, int lim, long nb, char *tab)
{
	while (len > lim)
	{
		tab[len - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*tab;
	int		len;
	int		lim;

	len = 0;
	lim = 0;
	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
		lim = 1;
	len = ft_size(nb);
	if (nb < 0)
		nb = -nb;
	tab = ft_calloc(len + 1, sizeof(char));
	if (!tab)
		return (NULL);
	if (lim == 1)
		tab[0] = '-';
	ft_tab(len, lim, nb, tab);
	tab[len + 1] = 0;
	return (tab);
}

/*
int	main(void)
{
	char	*result = ft_itoa(-2147483648LL);
	printf("%s", result);
	free(result);
	return (0);
}*/
