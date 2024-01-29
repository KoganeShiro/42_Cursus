/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:43:06 by hehuang           #+#    #+#             */
/*   Updated: 2023/07/23 20:43:12 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_numbers(int nb, t_list *dict, int start)
{
	if (nb >= 100)
	{
		ft_find(nb / 100, dict, start--);
		ft_find(100, dict, 0);
		nb = nb % 100;
	}
	if (nb >= 20)
	{
		ft_find(((nb / 10) * 10), dict, start--); // pour qu il ne soit pas egal a 1
		nb = nb % 10;
	}
	if (nb != 0)
		ft_find(nb, dict, start--);
}

void	ft_putstr(char *letter, int start)
{
	int	i;

	i = 0;
	if (start != 1)
		write(1, " ", 1); //si un mot deja ecrit aff space
	while (letter[i] != '\0')
		write(1, &letter[i++], 1);
}

void	ft_find(int nb, t_list *dict, int start)
{
	int	i;

	i = 0;
	while (dict[i].nb != nb && dict[i].nb != 702)
		i++;
	if (dict[i].nb == nb)
		ft_putstr(dict[i].letters, start); //afficher en lettre le nb dans le dict
}

void	ft_print(long int result, t_list *dict)
{	
	int	start;

	start = 1; // il sert simplement a ne pas mettre un espace devant le 1er mot
	if (result == 0)
		ft_find(0, dict, 1);
	if (result >= 1000000000)
	{
		ft_numbers(result / 1000000000, dict, start--); 
		ft_find(1000000000, dict, start);
		result = result % 1000000000;
	}
	if (result >= 1000000)
	{
		ft_numbers(result / 1000000, dict, start--);
		ft_find(1000000, dict, start);
		result = result % 1000000;
	}
	if (result >= 1000)
	{
		ft_numbers(result / 1000, dict, start--);
		ft_find(1000, dict, start);
		result = result % 1000;
	}
	if (result < 1000)
		ft_numbers(result, dict, start--);
}

int	main(int argc, char *argv[])
{
	t_list		*dct;
	long int	result;

	if (argc < 2 || argc > 3)
	{
		write(1, "Besoin de 1 ou 2 arguments, ni plus, ni moins !", 47);
		return (0);
	}
	if (argc == 2)
	{
		dct = store_dictionnary("numbers.dict", -1);
		result = ft_atoi(argv[1]);
		error_handling(result, dct);
	}
	if (argc == 3)
	{
		dct = store_dictionnary(argv[1], -1);
		result = ft_atoi(argv[2]);
		error_handling(result, dct); //pour un autre dico, 1er valeur = file.dict 2e valeur = nb
	}
	ft_free(dct);
	write (1, "\n", 1);
}
