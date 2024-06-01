# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 19:12:47 by cejin             #+#    #+#              #
#    Updated: 2023/12/21 11:01:13 by cejin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
#CFLAGS += -Wall -Wextra -Werror -g -O3
CFLAGS += -Wall -Wextra -Werror -g
CLINKS = -lXext -lX11 -lm

MLX = minilibx
LIBMLX = $(MLX)/libmlx.a

### SOURCE FILES ###			
			
SRCS		= main.c window.c moove_and_zoom.c image.c rendering.c\
			mandelbrot.c julia.c

SRCS_UTILS	= ft_strcmp.c \
			ft_atodbl.c \
			ft_printf.c \
			print_char.c print_digit.c print_hex_ptr.c



SRCS_BONUS = main_bonus.c window_bonus.c \
			moove_and_zoom_bonus.c \
			image_bonus.c \
			rendering_bonus.c \
			mandelbrot_bonus.c \
			julia_bonus.c \
			burning_ship_bonus.c \
			ft_strcmp_bonus.c \
			ft_atodbl_bonus.c \
			ft_printf_bonus.c \
			print_char_bonus.c print_digit_bonus.c print_hex_ptr_bonus.c


### OBJECTS ###

OBJ_PATH = obj/
OBJ_BONUS_PATH = bonus_obj/

OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))
OBJS += $(addprefix $(OBJ_PATH), $(SRCS_UTILS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_BONUS_PATH), $(SRCS_BONUS:.c=.o))


### RULES ###

all: $(OBJ_PATH) $(NAME)

$(NAME):	$(LIBMLX) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBMLX) $(CLINKS)

${OBJ_PATH} ${OBJ_BONUS_PATH}:
		mkdir -p $@

bonus: 		 $(LIBMLX) $(OBJS_BONUS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS) $(LIBMLX) $(CLINKS)

$(LIBMLX):
		$(MAKE) -C $(MLX)

$(OBJ_PATH)%.o: src/%.c
		$(CC) $(CFLAGS) -Iincludes -c $< -o $@
$(OBJ_PATH)%.o: utils/%.c
		$(CC) $(CFLAGS) -Iincludes -c $< -o $@
		
$(OBJ_BONUS_PATH)%.o: bonus/%.c | $(OBJ_BONUS_PATH)
		$(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
		rm -f $(OBJ)
		rm -rf $(OBJ_PATH) $(OBJ_BONUS_PATH)

fclean: clean
		rm -f $(LIBMLX)
		rm -f $(NAME)

re:	fclean all bonus

.PHONY:	all clean fclean re bonus
