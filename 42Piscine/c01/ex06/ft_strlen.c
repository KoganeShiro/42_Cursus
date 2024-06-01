/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:09:47 by event             #+#    #+#             */
/*   Updated: 2023/07/10 14:26:10 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strlen(char *str)
{
	int	compteur_char;

	compteur_char = 0;
	while (str[compteur_char] != '\0')
	{
		compteur_char++;
	}
	return (compteur_char);
}
