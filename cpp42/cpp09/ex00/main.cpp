
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << 
            RED "Error: could not open file.\nUsage: ./btc [INPUT_FILE]" RESET
        << std::endl;
        return (0);
    }
    // parsing
        //check if the file follow the format:
            //"date | value" at every begining of the line
        //For that we have to check if the date follow this format:
            //Year-Month-Day
        //We also need to check if the value is a float or an unsigned int
            //between 0 and 1000

    BitcoinExchange exchange;

    if (exchange.setData(DATA_FILE) == EXIT_FAILURE) {
        std::cout <<
            "Problem with the DATA_FILE: " << DATA_FILE
        << std::endl;
    }
    exchange.convertValue(argv[1]);
    return (0);
}