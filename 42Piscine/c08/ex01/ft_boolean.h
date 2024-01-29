/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:38:07 by cejin             #+#    #+#             */
/*   Updated: 2023/07/20 10:51:49 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define SUCCESS 0
# define TRUE 1
# define FALSE 0
# define EVEN(x) (x % 2 == 0)
# define ODD_MSG "I have an odd number of arguments.\n"
# define EVEN_MSG "I have an even number of arguments.\n"

typedef int	t_bool;
#endif
