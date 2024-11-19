/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:51:36 by cejin             #+#    #+#             */
/*   Updated: 2024/11/17 19:06:15 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iomanip>
# include <iostream>
# include <fstream>
# include <string>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"


void	readFile(const std::string &file,
			const std::string &srcStr,
			const std::string &newStr);

std::string	replaceStr(std::string content,
			std::string srcStr, std::string newStr);

void	createFile(std::string file, std::string newContent);
