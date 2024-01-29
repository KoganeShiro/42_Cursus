# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cejin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 14:09:10 by cejin             #+#    #+#              #
#    Updated: 2023/07/26 16:18:48 by cejin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

gcc -Wall -Werror -Wextra ft_swap.c ft_putchar.c ft_putstr.c ft_strlen.c ft_strcmp.c -c
ar rc libft.a*.o
ranlib libft.a
rm *.o
