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

all: $(NAME) $(EXEC_NAME)

${OBJ_PATH}:
		mkdir -p ${OBJ_PATH}

${NAME}: ${OBJS}
			ar rc ${NAME} ${OBJS}

%.o: %.c
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			rm -f ${OBJS}
			rm -f ${OBJS_EXEC}
			rm -rf ${OBJ_PATH}

fclean: clean
			rm -f ${NAME}
			rm -f ${EXEC_NAME}

re: fclean all

.PHONY: all clean fclean re
