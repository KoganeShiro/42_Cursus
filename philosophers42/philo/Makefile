# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cejin <cejin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 12:54:14 by cejin             #+#    #+#              #
#    Updated: 2024/06/02 18:34:33 by cejin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS += -Wall -Werror -Wextra -pthread #-fsanitize=thread

OBJ_PATH = obj/
SRCS_PATH = src/

SRCS = utils.c time.c init.c philo.c main.c monitor.c

OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

NAME = philo


all: $(OBJ_PATH) $(NAME)

${OBJ_PATH}:
		mkdir -p ${OBJ_PATH}

${NAME}: ${OBJS}
			${CC} ${CFLAGS} -o $@ $^

${OBJ_PATH}%.o: ${SRCS_PATH}%.c
			${CC} ${CFLAGS} -Iincludes -c $< -o $@

clean:
			rm -f ${OBJS}
			rm -rf ${OBJ_PATH}

fclean: clean
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
