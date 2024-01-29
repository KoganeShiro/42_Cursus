/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:15:53 by event             #+#    #+#             */
/*   Updated: 2023/07/10 18:14:43 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	compteur;

	compteur = 0;
	while (src[compteur] != '\0' && compteur < n)
	{
		dest[compteur] = src[compteur];
		compteur++;
	}
	while (compteur < n)
	{
		dest[compteur] = '\0';
		compteur++;
	}
	return (dest);
}
