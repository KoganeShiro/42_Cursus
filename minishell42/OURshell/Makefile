# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 09:28:43 by vharatyk          #+#    #+#              #
#    Updated: 2024/06/22 18:54:56 by vharatyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -g -Wall -Wextra -Werror

###		SRCS DIRECTORIES	 ####
PIPEX_DIR = pipex/
PARSING_DIR = parsing/
BUILTINS_DIR = builtins/
UTILS_DIR = utils/
OBJ_PATH = obj/


				###	 	SRCS	 ###
SRCS = main.c signal.c #debug.c

SRCS_PIPEX = check_files.c execve.c get_next_line.c here_doc.c pipex.c redir.c cmd_utils.c open_files.c

SRCS_PARSING = create_command.c init.c input_create.c input_size.c parsing.c utils_env.c var.c add_var.c verif_command.c

SRCS_BUILTINS = builtins.c builtins_utils.c ft_cd.c ft_echo.c ft_env.c ft_exit.c ft_export.c ft_pwd.c ft_unset.c exec_export.c


SRCS_UTILS = free.c ft_cleanup.c ft_itoa.c ft_split.c get_next_line_utils.c utils_parsing.c utils_pipex.c utils.c utils_parsing2.c


				###		OBJS 	###
SRCS_ALL =	$(SRCS:.c=.o) $(addprefix $(UTILS_DIR), $(SRCS_UTILS:.c=.o)) $(addprefix $(PIPEX_DIR), $(SRCS_PIPEX:.c=.o)) $(addprefix $(PARSING_DIR), $(SRCS_PARSING:.c=.o)) $(addprefix $(BUILTINS_DIR), $(SRCS_BUILTINS:.c=.o))


OBJS += $(addprefix $(OBJ_PATH), $(SRCS_ALL:.c=.o))



NAME = minishell

all: $(OBJ_PATH) $(NAME)


${OBJ_PATH}:
		mkdir -p ${OBJ_PATH}

${NAME}: ${OBJS}
			${CC} ${CFLAGS} -o $@ $^ -lreadline


${OBJ_PATH}%.o: %.c
			mkdir -p $(dir $@)
			${CC} ${CFLAGS} -c $< -o $@ -Iincludes

clean:
			rm -f ${OBJS}
			rm -rf ${OBJ_PATH}

fclean: clean
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
