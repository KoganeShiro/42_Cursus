# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cejin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 17:47:38 by cejin             #+#    #+#              #
#    Updated: 2024/02/15 17:47:44 by cejin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wextra -Wall -g

SRCS = 	pipex.c utils.c error_handling.c ft_split.c

OBJ_PATH = obj/
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

NAME = pipex

all: $(OBJ_PATH) $(NAME)

${OBJ_PATH}:
		mkdir -p ${OBJ_PATH} 

${NAME}: ${OBJS}
			${CC} ${CFLAGS} -o $@ $^ 

${OBJ_PATH}%.o: %.c
			${CC} ${CFLAGS} -Iincludes -c $< -o $@

clean:
			rm -f ${OBJS}
			rm -rf ${OBJ_PATH}

fclean: clean
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
