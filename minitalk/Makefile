CC = cc
CFLAGS = -Werror -Wextra -Wall -g

SRCS_SERV = 	ft_utils.c server.c \
				printf/print_char.c printf/print_digit.c printf/print_hex_ptr.c printf/ft_printf.c

SRCS_CLIENT =	ft_utils.c client.c \
				printf/print_char.c printf/print_digit.c printf/print_hex_ptr.c printf/ft_printf.c


OBJ_PATH = obj/
SRCS_PATH = src/

OBJS_SERV = $(addprefix $(OBJ_PATH), $(SRCS_SERV:.c=.o))
OBJS_CLIENT = $(addprefix $(OBJ_PATH), $(SRCS_CLIENT:.c=.o))

SERVER = server

CLIENT = client

all: $(OBJ_PATH) $(SERVER) $(CLIENT)

${OBJ_PATH}:
		mkdir -p ${OBJ_PATH}

${SERVER}: ${OBJS_SERV}
			${CC} ${CFLAGS} -o $@ $^ 

${CLIENT}: ${OBJS_CLIENT}
			${CC} ${CFLAGS} -o $@ $^ 

${OBJ_PATH}%.o: ${SRCS_PATH}%.c
			mkdir -p $(dir $@)
			${CC} ${CFLAGS} -Iincludes -c $< -o $@

clean:
			rm -f ${OBJS_SERV} ${OBJS_CLIENT}
			rm -rf ${OBJ_PATH}

fclean: clean
			rm -f ${SERVER}
			rm -f ${CLIENT}

re: fclean all

.PHONY: all clean fclean re
