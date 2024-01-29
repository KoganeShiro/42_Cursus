/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:38:38 by cejin             #+#    #+#             */
/*   Updated: 2023/11/20 12:10:13 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FD_MAX
#  define FD_MAX 128
# endif

char	*get_next_line(int fd);
char	*read_file(int fd, char *buffer);
char	*extract_line(char *buffer);
char	*find_next_line(char *buffer);
char	*ft_strjoin(char *buffer, char *tmp);
int		ft_strchr(char *buffer, int new_line_ptr);
int		ft_strlen(char *buffer);
void	*ft_calloc(int str_len, int size);

#endif
