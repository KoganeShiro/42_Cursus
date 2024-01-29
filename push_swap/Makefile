CC = cc
CFLAGS = -Werror -Wextra -Wall -g

SRCS = 	error_handling.c main.c algo.c\
		ft_utils.c ft_split.c \
		ft_swap.c ft_reverse.c ft_rotate.c ft_push.c\
		tiny_sort.c ft_stacks.c ft_cost.c stack_utils.c

SRCS_CHECKER = bonus/checker.c \
				error_handling.c stack_utils.c algo.c \
				ft_utils.c ft_split.c \
				ft_swap.c ft_reverse.c ft_rotate.c ft_push.c\
				tiny_sort.c ft_stacks.c ft_cost.c
	
OBJ_PATH = obj/
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))
OBJS_CHECKER = $(addprefix $(OBJ_PATH), $(SRCS_CHECKER:.c=.o))

NAME = push_swap

BONUS = checker

all: $(OBJ_PATH) $(NAME)

bonus: $(OBJ_PATH) $(BONUS)

${OBJ_PATH}:
		mkdir -p ${OBJ_PATH}

${NAME}: ${OBJS}
			${CC} ${CFLAGS} -o $@ $^ 

${BONUS}: ${OBJS_CHECKER}
			${CC} ${CFLAGS} -o $@ $^ 

${OBJ_PATH}%.o: %.c
			mkdir -p $(dir $@)
			${CC} ${CFLAGS} -Iincludes -c $< -o $@

clean:
			rm -f ${OBJS}
			rm -rf ${OBJ_PATH}

fclean: clean
			rm -f ${NAME}
			rm -f ${BONUS}

re: fclean all

.PHONY: all clean fclean re
