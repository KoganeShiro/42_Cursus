/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:56:47 by cejin             #+#    #+#             */
/*   Updated: 2024/09/23 15:38:50 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

std::string	ft_toupper(char **argv)
{
	std::string	str;

	for (int i = 1; argv[i] != NULL; i++) {
		for (int j = 0; argv[i][j] != '\0'; j++) {
			str += toupper(argv[i][j]);
		}
	}
	return str;
}

int	main(int argc, char **argv)
{
	std::string	str;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		str = ft_toupper(argv);
		std::cout << str << std::endl;
	}
	return 0;
}