/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:51:42 by cejin             #+#    #+#             */
/*   Updated: 2023/10/20 17:49:07 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if ((s == 0 && d == 0) || n == 0)
		return (dest);
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main () {
	const char src[50] = "";
	char dest[50] = "sssf";
	
	printf("Before memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, 35);
	printf("ft_memcpy dest = %s\n", dest);
	memcpy(dest, src, 35);

}
*/