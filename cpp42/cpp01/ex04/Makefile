# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cejin <cejin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 15:26:42 by cejin             #+#    #+#              #
#    Updated: 2024/11/17 18:47:31 by cejin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = 	main.cpp \
		fileOperation.cpp \
		replaceStr.cpp

OBJ_PATH = obj/
OBJS += $(addprefix $(OBJ_PATH), $(SRCS:.cpp=.o))

NAME = somehowSed

all: $(OBJ_PATH) $(NAME)
	@echo "\r\033[K\033[38;2;0;170;0;1mSuccessfully compiled to \033[38;2;255;145;5;3m./$(NAME)\033[0m\033[38;2;0;170;0;1m!\033[0m"

${OBJ_PATH}:
		mkdir -p ${OBJ_PATH}

${NAME}: ${OBJS}
			${CC} ${CFLAGS} -o $@ $^


${OBJ_PATH}%.o: %.cpp
			${CC} ${CFLAGS} -c $< -o $@

clean:
			rm -f ${OBJS}
			rm -rf ${OBJ_PATH}

fclean: clean
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re