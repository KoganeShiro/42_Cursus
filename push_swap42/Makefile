CC = cc
CFLAGS = -Werror -Wextra -Wall -g

SRCS = error_handling.c algo.c\
	ft_utils.c ft_split.c \
	ft_swap.c ft_reverse.c ft_rotate.c ft_push.c\
	tiny_sort.c ft_stacks.c ft_cost.c stack_utils.c

MAIN = main.c

SRCS_CHECKER = bonus/checker.c

OBJ_PATH = obj/
SRCS_PATH = src/

OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))
OBJS_CHECKER = $(OBJS) $(addprefix $(OBJ_PATH), $(SRCS_CHECKER:.c=.o))
OBJS_MAIN = $(addprefix $(OBJ_PATH), $(MAIN:.c=.o))

NAME = push_swap
CHECKER = checker

${OBJ_PATH}:
	mkdir -p ${OBJ_PATH}

all: $(OBJ_PATH) $(NAME)

checker: $(OBJ_PATH) $(CHECKER)

$(NAME): ${OBJS} ${OBJS_MAIN}
		${CC} ${CFLAGS} -o $@ $^

$(CHECKER): ${OBJS} ${OBJS_CHECKER}
		${CC} ${CFLAGS} -o $@ $^

${OBJ_PATH}%.o: ${SRCS_PATH}%.c
		mkdir -p $(dir $@)
		${CC} ${CFLAGS} -Iincludes -c $< -o $@

${OBJ_PATH}%.o: %.c
		mkdir -p $(dir $@)
		${CC} ${CFLAGS} -Iincludes -c $< -o $@

clean:
		rm -f ${OBJS}
		rm -rf ${OBJ_PATH}

fclean: clean
		rm -f ${NAME}
		rm -f ${CHECKER}

re: fclean all

.PHONY: all clean fclean re
