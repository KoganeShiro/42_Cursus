/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:43:25 by hehuang           #+#    #+#             */
/*   Updated: 2023/07/23 20:43:29 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		len;

	len = 0;
	while (src[len] != '\0')
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_get_nb(int fd)
{
	int		i;
	char	buff[1]; //buffer, portion de memoire que l on va allouer au read (stockage de ce qu on va lire)
	char	*str;

	str = malloc(sizeof(char) * 128);
	if (str == NULL)
		return (0);
	i = 0;
	read(fd, buff, 1);
	while (buff[0] == '\n')
		read(fd, buff, 1);
	while (buff[0] >= '0' && buff[0] <= '9')
	{
		str[i] = buff[0];
		read(fd, buff, 1);
		i++;
	}
	return (str);
}

char	*ft_get_letters(int fd, char first)
{
	int		i;
	char	buff[1];
	char	*str;

	str = malloc(sizeof(char) * 128);
	if (str == NULL)
		return (0);
	i = 0;
	str[i++] = first;
	while (buff[0] != '\n')
	{
		read(fd, buff, 1); //fd = file descriptor, soit ce aue renvoit le open (dico)
		str[i] = buff[0];
		i++;
	}
	str[i - 1] = '\0';
	return (str);
}

long int	ft_atoi( char *str)
{
	long int	res;
	int			negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

t_list	*store_dictionnary(char *path, int i)
{
	t_list	*dct;
	char	buf[1];
	int		fd;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	dct = malloc((32 + 1) * sizeof(t_list));
	if (dct == NULL)
		return (0);
	while (++i < 32)
	{
		tmp = ft_get_nb(fd); //pour le malloc et le free apres sinon LEAK
		dct[i].nb = ft_atoi(tmp); //prend le nb et le atoi (ascii to int)
		free(tmp);
		read(fd, buf, 1);
		check_spaces(buf, fd);
		tmp = ft_get_letters(fd, buf[0]); //pour le malloc et le free
		dct[i].letters = ft_strdup(tmp); //prend les str
		free(tmp);
	}
	close(fd);
	dct[i].nb = 702;
	return (dct);
}
