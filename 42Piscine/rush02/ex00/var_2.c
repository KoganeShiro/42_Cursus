/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:43:37 by hehuang           #+#    #+#             */
/*   Updated: 2023/07/23 20:43:42 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	check_spaces(char *buf, int fd)
{
	while (buf[0] == ' ')
		read(fd, buf, 1);
	if (buf[0] == ':')
		read(fd, buf, 1);
	while (buf[0] == ' ')
		read(fd, buf, 1);
}

void	error_handling(long int result, t_list *dct)
{
	if (result < 0)
	{
		write(1, "Error", 5);
		return ;
	}
	if (result > 999999999999)
	{
		write(1, "Dict Error", 10);
		return ;
	}
	ft_print(result, dct);
}
