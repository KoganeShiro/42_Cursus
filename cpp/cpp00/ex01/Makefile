# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cejin <cejin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 13:40:09 by cejin             #+#    #+#              #
#    Updated: 2024/09/23 16:12:20 by cejin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp contact.cpp phoneBook.cpp

OBJ_PATH = obj/
OBJS += $(addprefix $(OBJ_PATH), $(SRCS:.cpp=.o))

NAME = phonebook

all: $(OBJ_PATH) $(NAME)


${OBJ_PATH}:
		mkdir -p ${OBJ_PATH}

${NAME}: ${OBJS}
			${CC} ${CFLAGS} -o $@ $^


${OBJ_PATH}%.o: %.cpp
			mkdir -p $(dir $@)
			${CC} ${CFLAGS} -c $< -o $@ -Iincludes

clean:
			rm -f ${OBJS}
			rm -rf ${OBJ_PATH}

fclean: clean
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re