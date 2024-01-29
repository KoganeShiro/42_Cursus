/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:13:47 by hehuang           #+#    #+#             */
/*   Updated: 2023/07/23 21:20:31 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_free(t_list *mylist)
{
	int	i;

	i = 0;
	while (mylist[i].nb != 702)
	{
		free(mylist[i].letters); //va rentrer dans le tableau de structure et free les chaine de caractere
		i++;
	}
	free(mylist);
	// free tableau de structure
}
