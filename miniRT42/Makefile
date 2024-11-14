# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cejin <cejin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 13:37:21 by cejin             #+#    #+#              #
#    Updated: 2024/11/13 11:27:24 by echapuis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_PATH	=	minilibx-linux
CC = cc
#CFLAGS = -Wall -Wextra -I$(MLX_PATH) -Ilibft -g
CFLAGS = -Wall -Werror -Wextra -I$(MLX_PATH) -Ilibft -g
LDFLAGS = -lXext -lX11 -lm -lz -I.

SRCS = 		main.c mlx.c hit.c obj_light.c \
			raytracing.c hit_sphere.c \
			get_color.c viewport.c light_ray.c \
			get_nearest_obj.c get_obj_color.c \
			glb_light.c hit_plane.c hit_cylinder.c 

SRCS_PARSE = init.c \
			parsing.c fill_struct.c \
			fill_check_camera.c fill_check_glb_lights.c \
			linked_list.c \
			fill_check_sphere.c fill_check_plane.c \
			set_position.c set_rgb.c fill_check_cylinder.c \
			set_normalized_vec.c function_check.c \

SRCS_UTILS = utils.c color_utils.c \
			math_functions.c math_equations.c \
			vec_functions_to.c vec_operations.c \
			cleanup.c vec_function.c
			#print_debug.c


OBJ_PATH = obj/
SRCS_PATH = src/
PARSE_PATH = src/parsing/
UTILS_PATH = src/utils/

SRCS_FILES = $(addprefix $(SRCS_PATH), $(SRCS))
PARSE_FILES = $(addprefix $(PARSE_PATH), $(SRCS_PARSE))
UTILS_FILES = $(addprefix $(UTILS_PATH), $(SRCS_UTILS))

ALL_SRCS = $(SRCS_FILES) $(PARSE_FILES) $(UTILS_FILES)

OBJS = $(ALL_SRCS:$(SRCS_PATH)%.c=$(OBJ_PATH)%.o)

NAME = miniRT

all: $(OBJ_PATH) $(NAME)

libft/libft.a:
	$(MAKE) -C libft

$(MLX_PATH)/libmlx.a:
	$(MAKE) -C $(MLX_PATH)

${OBJ_PATH}:
		mkdir -p ${OBJ_PATH}

${NAME}: ${OBJS} libft/libft.a $(MLX_PATH)/libmlx.a
			${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^


$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(PARSE_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(UTILS_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			make -C libft clean
			rm -f ${OBJS}
			rm -rf ${OBJ_PATH}

fclean: clean
			make -C libft fclean
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
