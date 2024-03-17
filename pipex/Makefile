# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cejin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 17:47:38 by cejin             #+#    #+#              #
#    Updated: 2024/02/29 19:38:58 by cejin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wextra -Wall -g

SRCS = 	pipex.c utils.c error_handling.c ft_split.c main.c

SRCS_BONUS = 	bonus/get_next_line.c  bonus/get_next_line_utils.c bonus/execve.c \
				bonus/pipex.c bonus/utils.c bonus/here_doc.c bonus/free.c \
				bonus/error_handling.c bonus/ft_split.c bonus/main.c

OBJ_PATH = obj/
OBJ_BONUS_PATH = bonus_obj/
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_BONUS_PATH), $(SRCS_BONUS:.c=.o))

NAME = pipex
BONUS = pipex_bonus

all: $(OBJ_PATH) ${OBJ_BONUS_PATH} $(NAME) $(BONUS)

bonus: ${OBJ_BONUS_PATH} $(BONUS)

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
			mkdir -p $(dir $@)
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
