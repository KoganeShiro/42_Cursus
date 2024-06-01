# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cejin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 15:25:46 by cejin             #+#    #+#              #
#    Updated: 2023/07/26 11:42:03 by cejin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
HEADER = ./includes/

OPTION = -I $(HEADER) -c

SRCS = ./src/ft_putchar.c \
	./src/ft_swap.c \
	./src/ft_putstr.c \
	./src/ft_strlen.c \
	./src/ft_strcmp.c

OBJS = $(SRCS:.c=.o)

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc $(CFLAGS) $(OPTION) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
