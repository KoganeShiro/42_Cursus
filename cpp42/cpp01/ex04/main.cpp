/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:52:19 by cejin             #+#    #+#             */
/*   Updated: 2024/11/17 18:42:19 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		readFile(argv[1], argv[2], argv[3]);
	}
	else
	{
		std::cout << RED
			"Usage: ./somehowSed FileName SrcStr NewStr"
		RESET << std::endl;
	}
}
