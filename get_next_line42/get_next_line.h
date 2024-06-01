/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:45:07 by cejin             #+#    #+#             */
/*   Updated: 2023/11/17 13:38:24 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

char	*get_next_line(int fd);
char	*read_file(int fd, char *buffer);
char	*extract_line(char *buffer);
char	*find_next_line(char *buffer);
char	*ft_strjoin(char *buffer, char *tmp);
int		ft_strchr(char *buffer, char new_line_ptr);
int		ft_strlen(char *buffer);
void	*ft_calloc(int str_len, int size);

#endif
