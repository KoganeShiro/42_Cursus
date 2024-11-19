/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:25:13 by cejin             #+#    #+#             */
/*   Updated: 2024/11/18 15:49:18 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iomanip>
# include <iostream> 
# include <string>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

# define DEBUG_MSG		"The impossible happened !😑\nYou have to debug this shit..."
# define INFO_MSG		"Did you leave me some food to do this job ? 🤑"
# define WARNING_MSG	"I am not paid enough for this 😡 (give me an extra cookie)"
# define ERROR_MSG		"The fuck did you do 🫠 ???"
# define DEFAULT		"*Harl is complaining about some nonsense again*"
# define LEVEL_NB		4

class Harl
{
private:

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

public:

	Harl();
	~Harl();

	void	complain(std::string level);
};
