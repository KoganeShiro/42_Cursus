/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:56:53 by cejin             #+#    #+#             */
/*   Updated: 2024/12/16 12:00:45 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    std::string arr[] = {"Hello", "World", "!"};
    size_t arrLength = sizeof(arr) / sizeof(arr[0]);

    iter(arr, arrLength, printElement);

    std::cout << "\n";

    char array[] = "Hey !";
    size_t arrayLength = sizeof(array) / sizeof(array[0]);

    iter(array, arrayLength, printElement);

    return 0;
}