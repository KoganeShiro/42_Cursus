/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:18:13 by cejin             #+#    #+#             */
/*   Updated: 2024/11/29 09:41:03 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

# define NB_IDEAS 100

class Brain
{
private:
    std::string ideas[NB_IDEAS];
    int  ideasCount;
    
public:
    Brain();
    Brain(const Brain &src);
    Brain &operator=(const Brain &src);

    void setNewIdea(std::string const &idea);
    std::string const getIdea(int i) const;
    int getIdeaCount() const;
    ~Brain();
};
