/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:52:25 by cejin             #+#    #+#             */
/*   Updated: 2024/12/16 15:38:26 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), arrLen(0)
{
    std::cout << GREEN
		"T_Array DEFAULT constructor is called"
	RESET << std::endl;
}

template <typename T>
Array<T>::Array(const Array &src) : array(new T[src.arrLen]), arrLen(src.arrLen)
{
    std::cout << GREEN
		"T_Array COPY constructor is called"
	RESET << std::endl;
    for (unsigned int i = 0; i < this->arrLen; i++) {
        this->array[i] = src.array[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
    std::cout << GREEN
		"T_Array COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
    if (this != src) {
        delete[] this->array;
        this->array = new T[src.arrLen];
        this->arrLen = src.arrLen;
        for (unsigned int i = 0; i < this->len; i++) {
		    this->array[i] = src.array[i];
        }
    }
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), arrLen(n)
{
    std::cout << GREEN
		"T_Array PARAMETERIZED CONSTRUCTOR is called"
	RESET << std::endl;
    for (unsigned int i = 0; i < n; ++i) {
        array[i] = T();
    }
}

template <typename T>
T   &Array<T>::operator[](unsigned int index)
{
    if (index >= this->arrLen) {
        throw std::out_of_range("OUT_OF_RANGE");
    }
    return (this->array[index]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
    if (index >= this->arrLen) {
        throw std::out_of_range("OUT_OF_RANGE");
    }
    return (this->array[index]);
}

template <typename T>
unsigned int Array<T>::size() const //getter
{
    return (this->arrLen);
}

template <typename T>
Array<T>::~Array()
{
    std::cout << RED
		"T_Array Destructor is called"
	RESET << std::endl;
    if (this->array != NULL) {
        delete[] this->array;
    }
}
