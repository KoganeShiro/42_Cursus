/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceStr.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:02:45 by cejin             #+#    #+#             */
/*   Updated: 2024/11/17 19:22:27 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

//std::string::npos --> if find() == false
//newContent.append(content, prev, pos - prev);
	//append things before finding srcStr
	//if there is no thing before srcStr it will append NULL

std::string	replaceStr(std::string content,
			std::string srcStr, std::string newStr)
{
	std::string	newContent;
	std::size_t	prev = 0;
	std::size_t	pos = content.find(srcStr, prev);
	std::string	word;

	while (pos != std::string::npos) {
		newContent.append(content, prev, pos - prev);
		newContent.append(newStr);
		prev = pos + srcStr.length();
		pos = content.find(srcStr, prev);
	}
	newContent.append(content, prev, content.length() - prev);
	return (newContent);
}
