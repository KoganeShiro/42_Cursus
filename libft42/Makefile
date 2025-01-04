NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC_PART1 =	ft_isalpha.c ft_calloc.c ft_strdup.c \
			ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c \
			ft_strlcat.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c \
			ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c

SRC_PART2 =	ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_putstr_fd.c

SRC_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
        ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
        ft_lstclear.c ft_lstiter.c ft_lstmap.c

DIR_PART1 = part_1/
DIR_PART2 = part_2/
DIR_B = bonus/

SRC_PART1 := $(addprefix $(DIR_PART1), $(SRC_PART1))
SRC_PART2 := $(addprefix $(DIR_PART2), $(SRC_PART2))
SRC_B := $(addprefix $(DIR_B), $(SRC_B))

OBJS_PART1 = ${SRC_PART1:.c=.o}
OBJS_PART2 = ${SRC_PART2:.c=.o}
OBJS_B = ${SRC_B:.c=.o}


all: ${NAME}

${NAME}: ${OBJS_PART1} ${OBJS_PART2}
		ar rc ${NAME} ${OBJS}

bonus: ${OBJS_PART1} ${OBJS_PART2} ${OBJS_B}
		ar rc ${NAME} ${OBJS} ${OBJS_B}


%.o: %.c 
		$(CC) ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
		rm -f ${OBJS_PART1} ${OBJS_PART2} ${OBJS_B}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
