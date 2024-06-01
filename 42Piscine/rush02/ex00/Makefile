# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cejin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 11:23:00 by cejin             #+#    #+#              #
#    Updated: 2023/07/23 18:09:48 by hehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = ${wildcard *.c}

OBJS = ${SRCS:.c=.o}

NAME = rush-02

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	gcc ${CFLAGS} $^ -o $@

%.o: %.c
	gcc ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
