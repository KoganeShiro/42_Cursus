/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:00:37 by cejin             #+#    #+#             */
/*   Updated: 2024/12/28 11:28:52 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <stdint.h>
#include <limits>
#include <climits>
#include <cstdlib>
#include <stdexcept>
#include "vector"
#include "stack"

# define RED "\033[1;31m"
# define ORANGE "\033[38;2;255;145;5;3m"
# define BGREEN "\033[0m\033[38;2;0;170;0;1m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

#define JACOBSTHAL_SIZE 34

template<class T>
void    printContainer(T& container)
{
    for (size_t i = 0; i < container.size() ; i++) {
        std::cout << "[" << container[i] << "]" ;
    }
    std::cout << std::endl;
}

template<typename T>
T parseInputNumbers(int argc, char **argv)
{
    T container;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg.empty()) {
            throw std::invalid_argument("Empty argument provided");
        }

        size_t start = 0;
        if (arg[0] == '+') {
            start = 1;
        }
        for (size_t j = start; j < arg.length(); ++j) {
            if (!std::isdigit(arg[j])) {
                throw std::invalid_argument(YELLOW "Argument '" + arg + "' is not a valid positive integer !" RESET);
            }
        }

        char* endptr;
        long value = std::strtol(arg.c_str(), &endptr, 10);
        if (*endptr != '\0' || value < 0 || value > INT_MAX) {
            throw std::invalid_argument(YELLOW "Argument '" + arg + "' is out of valid integer range !" RESET);
        }
        container.push_back(static_cast<int>(value));
    }
    //std::cout << container.size() << std::endl;
    return (container);
}

class PmergeMe
{
private:
    /*
   [a, b, c, d | e, f, g, h]
    ^        ^   ^        ^
    i     first  i+size  second
        segment         segment
            end            end
    */
    template<class T>
    static void	sortPairs(T& container, std::size_t segmentSize)
    {
        std::size_t pairSize = 2 * segmentSize;
        for (size_t i = 0 ; pairSize + i <= container.size() ; i += pairSize) {
            std::size_t firstSegmentEnd = i + segmentSize - 1;
            std::size_t secondSegmentEnd = i + pairSize - 1;

            if (container[firstSegmentEnd] > container[secondSegmentEnd]) {
                std::swap_ranges(container.begin() + i,
                                container.begin() + i + segmentSize,
                                container.begin() + i + segmentSize);
            }
        }
    }

    // Binary search for insertion position
    template<class T>
    static size_t binarySearch(T& container, int target, size_t start, size_t end)
    {
        while (start < end) {
            size_t mid = start + (end - start) / 2;
            if (container[mid] > target) {
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }
        return (start);
    }

    static size_t getNextJacobsthalIndex(size_t& jacob_idx, size_t max_size)
    {
        while (jacob_idx < JACOBSTHAL_SIZE && 
               JACOBSTHAL_SEQUENCE[jacob_idx] <= max_size) {
            ++jacob_idx;
        }
        return (jacob_idx);
    }

    template<class T>
    static void insertSegment(T& sorted_container, 
                            T& main_container,
                            typename T::iterator it, 
                            size_t size,
                            typename T::iterator end)
    {
        if (it + size <= end) {
            T segment;
            for (size_t i = 0; i < size && (it + i) != end; ++i) {
                segment.push_back(*(it + i));
            }
            
            for (typename T::iterator seg_it = segment.begin(); seg_it != segment.end(); ++seg_it) {
                size_t pos = binarySearch(sorted_container, *seg_it, 0, sorted_container.size());
                sorted_container.insert(sorted_container.begin() + pos, *seg_it);
            }
            
            main_container.erase(it, it + size);
        }
    }

    template<class T>
    static void insertNonJacobsthalElements(T& sorted_container, 
                                        T& main_container,
                                        size_t num_pairs,
                                        size_t jacob_idx,
                                        size_t size)
    {
        for (size_t i = 1; i <= num_pairs; ++i) {
            bool already_inserted = false;
            for (size_t j = 0; j < jacob_idx; ++j) {
                if (i == JACOBSTHAL_SEQUENCE[j]) {
                    already_inserted = true;
                    break;
                }
            }
            if (!already_inserted && i * size < main_container.size()) {
                typename T::iterator insert_it = main_container.begin() + (i * size);
                insertSegment(sorted_container, main_container, insert_it, size, main_container.end());
            }
        }

        // Process any remaining elements in main_container
        while (!main_container.empty()) {
            typename T::iterator it = main_container.begin();
            size_t pos = binarySearch(sorted_container, *it, 0, sorted_container.size());
            sorted_container.insert(sorted_container.begin() + pos, *it);
            main_container.erase(it);
        }
    }

    template<class T>
    static void insertSortedSegments(T& container, std::size_t size)
    {
        if (container.size() < size * 3 || size == 1) {
            T sorted_container;
            T main_container = container;
            
            typename T::iterator it = main_container.begin();
            if (it + size <= main_container.end()) {
                // Insert initial segment
                sorted_container.insert(sorted_container.begin(), it, it + size);
                main_container.erase(it, it + size);

                size_t num_pairs = (container.size() - size) / size;
                size_t jacob_idx = 0;

                while (jacob_idx < JACOBSTHAL_SIZE && num_pairs > 0) {
                    size_t insert_pos = JACOBSTHAL_SEQUENCE[jacob_idx];
                    if (insert_pos > num_pairs) break;

                    if (insert_pos * size < main_container.size()) {
                        typename T::iterator insert_it = main_container.begin() + (insert_pos * size);
                        insertSegment(sorted_container, main_container, insert_it, size, main_container.end());
                    }
                    jacob_idx = getNextJacobsthalIndex(jacob_idx, num_pairs);
                }

                insertNonJacobsthalElements(sorted_container, main_container, num_pairs, jacob_idx, size);

                // Verify all elements are processed
                if (!main_container.empty()) {
                    for (typename T::iterator it = main_container.begin(); it != main_container.end(); ++it) {
                        size_t pos = binarySearch(sorted_container, *it, 0, sorted_container.size());
                        sorted_container.insert(sorted_container.begin() + pos, *it);
                    }
                }
                container = sorted_container;
            }
        }
    }


public:
    static const size_t JACOBSTHAL_SEQUENCE[JACOBSTHAL_SIZE];

    template<typename T>
    static void mergeInsertionSort(T& container, std::size_t segmentSize)
    {

        if (container.empty() || container.size() == 1
                || container.size() < segmentSize * 2) {
            return;
        }
        sortPairs(container, segmentSize);
        mergeInsertionSort(container, segmentSize * 2);
        insertSortedSegments(container, segmentSize);
    }
};

class SortingError : public std::runtime_error
{
public:
     explicit SortingError(const std::string& msg) : std::runtime_error(msg) {}
};

class Timer
{
private:
    timespec startTime;

public:
    Timer() {
        clock_gettime(CLOCK_MONOTONIC, &startTime);
    }

    double getElapsedMicroseconds() const {
        timespec currentTime;
        clock_gettime(CLOCK_MONOTONIC, &currentTime);
        return ((currentTime.tv_sec - startTime.tv_sec) * 1e9 +
                (currentTime.tv_nsec - startTime.tv_nsec)) / 1000.0;
    }
};
