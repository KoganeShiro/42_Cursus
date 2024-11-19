/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:52:19 by cejin             #+#    #+#             */
/*   Updated: 2024/11/18 16:23:51 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		Harl	harl;
		if (std::string(argv[1]) == "42") {
			harl.complain("DEBUG");
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			harl.complain("no");
		}
		else {
			harl.complain(argv[1]);
		}
	}
	else
	{
		std::cout << RED
			"Usage: ./harlComplain LEVEL"
		RESET << std::endl;
	}
}
