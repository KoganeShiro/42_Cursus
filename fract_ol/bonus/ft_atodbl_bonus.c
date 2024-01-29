/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:18:22 by cejin             #+#    #+#             */
/*   Updated: 2023/12/20 17:41:00 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	skip_whitespaces(char *av_value)
{
	int		i;

	i = 0;
	while (av_value[i] && ((av_value[i] >= '\t'
				&& av_value[i] <= '\r') || av_value[i] == ' '))
		i++;
	if (av_value[i] == '-' || av_value[i] == '+')
		i++;
	return (i);
}

int	what_sign(char *av_value)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while (av_value[i] != '\0' && (av_value[i] == '+' || av_value[i] == '-'))
	{
		if (av_value[i] == '-')
			sign = -1;
		i++;
	}
	return (sign);
}

double	ft_atodbl(char *av_value)
{
	int		i;
	int		sign;
	long	res;
	double	decimal;
	double	pow;

	i = skip_whitespaces(av_value);
	sign = what_sign(av_value);
	res = 0;
	pow = 1;
	decimal = 0;
	while (av_value[i] != '.' && av_value[i] != '\0'
		&& (av_value[i] >= '0' && av_value[i] <= '9'))
		res = res * 10 + (av_value[i++] - '0');
	if (av_value[i] == '.')
		i++;
	while (av_value[i] != '\0'
		&& (av_value[i] >= '0' && av_value[i] <= '9'))
	{
		pow /= 10;
		decimal = decimal + (av_value[i] - '0') * pow;
		i++;
	}
	return ((res + decimal) * sign);
}

/*
int main(int argc,char **argv)
{
	if (argc == 2)
	{
		double res = ft_atodbl(argv[1]);
		printf("%f\n", res);
	}
	return (0);
}
*/
