/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:19:47 by cejin             #+#    #+#             */
/*   Updated: 2024/12/19 18:20:14 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(void)
{
	return (this->c.begin());
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(void)
{
	return (this->c.end());
}
