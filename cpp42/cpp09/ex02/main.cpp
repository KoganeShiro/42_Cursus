
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
        std::deque<int>	numbers;
        numbers = parseInputNumbers<std::deque<int> >(argc, argv);

        //std::vector<int> numbers;
        //numbers = parseInputNumbers<std::vector<int> >(argc, argv);

        std::cout <<
            "====Container====" <<
        std::endl;
        std::cout << "Before: ";
        printContainer(numbers);

        Timer timer;
        PmergeMe::mergeInsertionSort(numbers, 1);
        double elapsed = timer.getElapsedMicroseconds();

        std::cout << "After: ";
        printContainer(numbers);
        
        std::cout <<
            "Time to process " << numbers.size() 
            << " elements: " << elapsed << " us"
        << std::endl;

        return (0);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
}
