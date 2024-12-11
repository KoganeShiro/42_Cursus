/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:23:55 by cejin             #+#    #+#             */
/*   Updated: 2024/12/10 13:27:50 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data ptr;
    uintptr_t serializedVal;
    Data *deserializedVal;

    std::cout << "----------------------" << std::endl;
    ptr.value = 10;
    std::cout << "Data: " << ptr.value << std::endl;
    serializedVal = Serializer::serialize(&ptr);
    std::cout << "Serialized data: " << serializedVal << std::endl;
    deserializedVal = Serializer::deserialize(serializedVal);
    std::cout << "Deserialized data: " << deserializedVal->value << std::endl;
    
    std::cout << "----------------------" << std::endl;

    ptr.value = 42;
    serializedVal = Serializer::serialize(&ptr);
    std::cout << "Data: " << ptr.value << std::endl;
    std::cout << "Serialized data: " << serializedVal << std::endl;
    deserializedVal = Serializer::deserialize(serializedVal);
    std::cout << "Deserialized data: " << deserializedVal->value << std::endl;
    std::cout << "----------------------" << std::endl;

    return (0);
}
