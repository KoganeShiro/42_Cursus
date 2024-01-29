/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:42:41 by hehuang           #+#    #+#             */
/*   Updated: 2023/07/23 20:50:58 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char	*letters;
	int		nb;
}		t_list;

void		ft_numbers(int nb, t_list *dict, int start);
void		ft_find(int nb, t_list *dict, int start);
void		ft_putstr(char *letters, int start);
void		ft_print(long int result, t_list *dict);
void		error_handling(long int result, t_list *dct);
void		check_spaces(char *buf, int fd);
void		ft_free(t_list *mylist);

char		*ft_get_nb(int fd);
char		*ft_strdup(char *src);
char		*ft_get_letters(int fd, char first);

t_list		*store_dictionnary(char *path, int i);

long int	ft_atoi(char *str);

#endif
