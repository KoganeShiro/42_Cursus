# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cejin <cejin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 10:29:10 by echapuis          #+#    #+#              #
#    Updated: 2024/10/17 13:57:54 by cejin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -c -g

INCLUDE = libft.h

#echo $(find . -name "ft_*.c" -exec basename {} \;)"

SRC_BONUS =  ft_lstnew.c \
      ft_lstadd_front.c \
      ft_lstsize.c \
      ft_lstlast.c \
      ft_lstadd_back.c \
      ft_lstdelone.c \
      ft_lstclear.c \
      ft_lstiter.c \
      ft_lstmap.c


SRC = ft_atoi.c \
      get_next_line.c \
      get_next_line_utils.c \
      ft_atof.c \
      ft_printf.c \
      ft_bzero.c \
      ft_isalnum.c \
      ft_isalpha.c \
      ft_isascii.c \
      ft_isdigit.c \
      ft_isprint.c \
      ft_memcpy.c \
      ft_memchr.c \
      ft_memmove.c \
      ft_memset.c \
      ft_strdup.c \
      ft_strlcat.c \
      ft_strlcpy.c \
      ft_memcmp.c \
      ft_strchr.c \
      ft_strlen.c \
      ft_toupper.c \
      ft_tolower.c \
      ft_strrchr.c \
      ft_strnstr.c \
      ft_strncmp.c \
      ft_calloc.c \
      ft_strjoin.c \
      ft_substr.c \
      ft_itoa.c \
      ft_strtrim.c \
      ft_strmapi.c \
      ft_striteri.c \
      ft_putchar_fd.c \
      ft_putstr_fd.c \
      ft_putendl_fd.c \
      ft_putnbr_fd.c \
      ft_split.c \
	  ft_putnbr_un_fd.c \
	  ft_putnbr_base.c \
	  ft_putptr.c \
	  ft_strcat.c \
	  ft_strcmp.c \
      
NAME = libft.a

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: all $(OBJ_BONUS)
	ar rs $(NAME) $(OBJ_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
