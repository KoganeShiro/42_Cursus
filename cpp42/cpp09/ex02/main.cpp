/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:00:21 by cejin             #+#    #+#             */
/*   Updated: 2024/12/28 11:44:12 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    try {
        if (argc < 2) {
            std::cout <<
                ORANGE "Usage: ./PmergeMe N1 N2 ... Nx" RESET <<
            std::endl; 
            return (0);
        }
        std::deque<int>	deque;
        deque = parseInputNumbers<std::deque<int> >(argc, argv);

        std::vector<int> vector;
        vector = parseInputNumbers<std::vector<int> >(argc, argv);

        std::cout <<
            "====Container====" <<
        std::endl;
        std::cout << "Before: ";
        printContainer(vector);

        Timer timerV;
        PmergeMe::mergeInsertionSort(vector, 1);
        double elapsedVector = timerV.getElapsedMicroseconds();

        Timer timerD;
        PmergeMe::mergeInsertionSort(deque, 1);
        double elapsedDeque = timerD.getElapsedMicroseconds();


        std::cout << "After: ";
        printContainer(vector);
        
        std::cout <<
            "Time to process " << vector.size() 
            << " vector elements: " << elapsedVector << " us"
        << std::endl;
        std::cout <<
            "Time to process " << deque.size() 
            << " deque elements: " << elapsedDeque << " us"
        << std::endl;

        return (0);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
}
