/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:55:06 by cejin             #+#    #+#             */
/*   Updated: 2023/11/03 15:46:37 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printnbr(int n);
int		ft_printchar(const char c);
int		ft_printstr(const char *str);
int		ft_printptr(unsigned long long ptr);
int		ft_printf(const char *format, ...);
int		ft_printunsigned(unsigned int n);
int		printf_format(va_list args, const char format);
int		ft_printhex(unsigned long nb, char *hex);

void	ft_putchar(const char c);

#endif
