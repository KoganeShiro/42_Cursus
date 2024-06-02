/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:51:22 by cejin             #+#    #+#             */
/*   Updated: 2023/10/22 19:24:16 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*src;

	src = (char *)s;
	i = 0;
	while (n != 0)
	{
		src[i] = 0;
		i++;
		n--;
	}
	return ;
}