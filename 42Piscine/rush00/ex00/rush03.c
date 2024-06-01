/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:17:21 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/09 16:16:44 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_put_first_line(int size)
{
	int	col;

	col = 0;
	ft_putchar('A');
	if (size == 1)
	{
		ft_putchar('\n');
		return ;
	}
	while (col < (size - 2))
	{
		ft_putchar('B');
		col++;
	}
	if (size > 1)
		ft_putchar('C');
	ft_putchar('\n');
}

void	ft_put_end_line(int size)
{
	int	col;

	col = 0;
	ft_putchar('A');
	while (col < (size - 2))
	{
		ft_putchar('B');
		col++;
	}
	if (size > 1)
		ft_putchar('C');
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	row;
	int	col;

	if (x < 1 || y < 1)
		return ;
	row = 0;
	col = 0;
	ft_put_first_line(x);
	if (y == 1)
		return ;
	while (row < y - 2)
	{
		ft_putchar('B');
		while (col < (x - 2))
		{
			ft_putchar(' ');
			col++;
		}
		row++;
		col = 0;
		if (x > 1)
			ft_putchar('B');
		ft_putchar('\n');
	}
	ft_put_end_line(x);
}
