/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:01:02 by cejin             #+#    #+#             */
/*   Updated: 2024/11/16 17:15:08 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

# define GREEN "\033[1;32m"
# define RESET "\033[0m"

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*strPtr = &str;
	std::string	&strRef = str;

	std::cout << GREEN "Memory addresses:\n" RESET;
	std::cout << "Original string address: " << &str << std::endl;
	std::cout << "Address held by PTR: 	 " << strPtr << std::endl;
	std::cout << "Address held by REF:	 " << &strRef << std::endl;
	std::cout << "\n";
	std::cout << GREEN "Values:\n" RESET;
	std::cout << "Original string value:	" + str << std::endl;
	std::cout << "Value pointed to:	" + *strPtr << std::endl;
	std::cout << "Value referenced:	" + strRef << std::endl;

	return (0);
}
