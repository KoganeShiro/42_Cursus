# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cejin <cejin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 13:52:44 by cejin             #+#    #+#              #
#    Updated: 2023/11/10 16:31:55 by cejin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Werror -Wextra -Wall

SRCS = ft_printf.c print_char.c print_digit.c \
		print_hex_ptr.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

${NAME}: ${OBJS}
			ar rc ${NAME} ${OBJS}

%.o: %.c
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			rm -f ${OBJS}

fclean: clean
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re