/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:14:09 by cejin             #+#    #+#             */
/*   Updated: 2023/10/21 12:09:06 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <stdio.h>
 
int main()
{
    char ch;
 
    ch = '';
	printf("\nft_toupper: %c", ft_toupper(ch));
	printf("\ntoupper: %c\n", toupper(ch));
	
    return 0;
}
*/