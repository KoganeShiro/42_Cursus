/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:17:42 by cejin             #+#    #+#             */
/*   Updated: 2024/12/27 15:21:40 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const size_t PmergeMe::JACOBSTHAL_SEQUENCE[JACOBSTHAL_SIZE] = {
    2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 
    21846, 43690, 87382, 174762, 349526, 699050, 1398102, 2796202, 
    5592406, 11184810, 22369622, 44739242, 89478486, 178956970, 
    357913942, 715827882, 1431655764, 2863311530, 5726623062, 11453246122
};

/*
Pair Formation:
    Always sort within pairs first
    Then sort pairs by their larger elements

Chain Creation:
    Main chain starts with smallest element of first pair (b₁)
    Followed by all 'a' values in sorted order
    Pend contains remaining 'b' values

Jacobsthal Numbers:
    Used for optimal insertion order * 2
    Sequence: 2, 2, 6, 10, 22, 42, 86, 170
    Each number tells you which pending element to insert next

Binary Insertion:
    Used for both Jacobsthal-ordered insertions and regular insertions
    More efficient than linear insertion

https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
*/