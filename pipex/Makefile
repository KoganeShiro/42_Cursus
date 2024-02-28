# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cejin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 17:47:38 by cejin             #+#    #+#              #
#    Updated: 2024/02/27 10:40:08 by cejin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wextra -Wall -g

SRCS = 	pipex.c utils.c error_handling.c ft_split.c main.c

SRCS_BONUS = bonus/get_next_line.c 

OBJ_PATH = obj/
OBJ_BONUS_PATH = bonus_obj/
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_BONUS_PATH), $(SRCS_BONUS:.c=.o))

NAME = pipex

all: $(OBJ_PATH) ${OBJ_BONUS_PATH} $(NAME)

${OBJ_PATH}:
		mkdir -p ${OBJ_PATH} 

${OBJ_BONUS_PATH}:
		mkdir -p ${OBJ_BONUS_PATH}

${NAME}: ${OBJS}
			${CC} ${CFLAGS} -o $@ $^ 

${BONUS}: ${OBJS_BONUS}
			${CC} ${CFLAGS} -o $@ $^

${OBJ_PATH}%.o: %.c
			${CC} ${CFLAGS} -Iincludes -c $< -o $@

${OBJ_BONUS_PATH}%.o: %.c
			${CC} ${CFLAGS} -Iincludes -c $< -o $@

clean:
			rm -f ${OBJS}
			rm -rf ${OBJ_PATH}
			rm -f ${OBJS_BONUS}
			rm -rf ${OBJ_BONUS_PATH}

fclean: clean
			rm -f ${NAME}
			rm -f ${BONUS}

re: fclean all

.PHONY: all clean fclean re
