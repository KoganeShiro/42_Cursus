/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileOperation.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:04:00 by cejin             #+#    #+#             */
/*   Updated: 2024/11/17 19:22:05 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

// Use .c_str() to convert std::string to const char*
void	readFile(const std::string &file,
			const std::string &srcStr,
			const std::string &newStr)
{
	std::ifstream	aFile;
	std::string		content;

	aFile.open(file.c_str());
	if (aFile.is_open()) {
		getline(aFile, content, '\0');
		content = replaceStr(content, srcStr, newStr);
		createFile(file, content);
		aFile.close();
	}
	else {
		std::cerr <<
			"ERROR opening file: " + file
		<< std::endl;
	}
}

//newFile: file.replace
void	createFile(std::string file, std::string newContent)
{
	std::ofstream	newFile((file + ".replace").c_str(), std::ios::trunc);

	if (!newFile.is_open()) {
		std::cerr <<
			"ERROR opening replace file:" + file + ".replace"
		<< std::endl;
	}
	newFile << newContent;
	newFile.close();
}
