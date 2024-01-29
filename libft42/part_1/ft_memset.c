/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:51:47 by cejin             #+#    #+#             */
/*   Updated: 2023/10/20 17:49:32 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*src;

	src = s;
	while (n > 0)
	{
		*src = (unsigned char)c;
		src++;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "almost every programmer should know memset!";
  ft_memset(str,'-',6);
  puts (str);
  return 0;
}
*/