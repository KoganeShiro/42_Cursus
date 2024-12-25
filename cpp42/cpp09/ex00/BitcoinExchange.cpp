/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:43:07 by cejin             #+#    #+#             */
/*   Updated: 2024/12/25 19:22:22 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << GREEN
		"BitcoinExchange DEFAULT constructor is called"
	RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : map(src.map)
{
    std::cout << GREEN
		"BitcoinExchange COPY constructor is called"
	RESET << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
    std::cout << GREEN
		"BitcoinExchange COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
    if (this != &src) {
        *this = src;
    }
    return (*this);
}

#define YEAR 4
#define MONTH 7
#define DAY 10

# define NB_OF_MONTH 12
# define MONTH_OUT_OF_RANGE YELLOW "Month out of range" RESET
# define DAY_OUT_OF_RANGE YELLOW "Day out of range" RESET
# define VALUE_OUT_OF_RANGE YELLOW "Value out of range" RESET
# define INVALID_DATA YELLOW "Invalid date format" RESET

static bool _isBissextileYear(unsigned int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return (true);
    }
    return (false);
}

static int _getDayCount(unsigned int year, unsigned int month)
{
    static const unsigned int daysInMonth[] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    if (month == 2 && _isBissextileYear(year) == true) {
        return (29);
    }
    return (daysInMonth[month - 1]);
}

//year-month-day
//xxxx-xx-xx
static bool _isCorrectDate(const std::string &date)
{
    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);

    for (int i = 0; i < YEAR; ++i) {
        if (!isdigit(date[i]))
            return (false);
    }
    for (int i = 5; i < MONTH; ++i) {
        if (!isdigit(date[i]))
            return (false);
    }
    for (int i = 8; i < DAY; ++i) {
        if (!isdigit(date[i]))
            return (false);
    }
    const int year = atoi(date.substr(0, 4).c_str());
    const int month = atoi(date.substr(5, 2).c_str());
    const int day = atoi(date.substr(8, 2).c_str());
    if (month <= 0 || NB_OF_MONTH < month) {
		throw (std::out_of_range(MONTH_OUT_OF_RANGE));
    }
	if (day <= 0 || _getDayCount(year, month) < day) {
		throw (std::out_of_range(DAY_OUT_OF_RANGE));
    }
    return (true);
}

static bool _parseLine(const std::string &line,
	std::map<std::string, float> &map, char delimiter)
{
    std::istringstream stream(line);
    std::string date, valueStr;
    float value;

    if (std::getline(stream, date, delimiter) && std::getline(stream, valueStr)) {
        //remove whitespaces
        date.erase(std::remove_if(date.begin(), date.end(), ::isspace), date.end());

        if (!_isCorrectDate(date)) {
            throw std::invalid_argument(INVALID_DATA);
        }

        //convert valueStr to float
        std::istringstream valueStream(valueStr);
        valueStream >> value;

        if (!valueStream || valueStream.fail()) {
            throw std::out_of_range(VALUE_OUT_OF_RANGE);
        }

        map[date] = value;
        return (true);
    }
    return (false);
}

template <typename K, typename V>
void printMap(const std::map<K, V>& map)
{
    for (typename std::map<K, V>::const_iterator it = map.begin(); it != map.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

static bool _hasCorrectExtension(const std::string& fileName, const std::string& expectedExtension)
{
    size_t dotPosition = fileName.rfind('.');
    
    if (dotPosition == std::string::npos || dotPosition == 0) {
        return (false);
    }
    std::string extension = fileName.substr(dotPosition + 1);
    return (extension == expectedExtension);
}

int BitcoinExchange::setData(std::string const &fileName)
{
	std::ifstream infileDB(fileName.c_str());

	if (!_hasCorrectExtension(fileName, "csv")) {
        std::cerr << "DATA_FILE" << DATA_FILE << "must have a .csv extension" << std::endl;
        return (EXIT_FAILURE);
    }
	if (!infileDB.is_open())
	{
		std::cerr << "Couldn't open database file, check permissions" << std::endl;
		return (EXIT_FAILURE);
	}
	
	std::string line;
    unsigned int i = 0;
	if (!std::getline(infileDB, line)) {
        std::cerr <<
			YELLOW "Error: File is empty or could not read the first line" RESET
		<< std::endl;
        return (EXIT_FAILURE);
    }
    try {
		while (std::getline(infileDB, line)) {
			//std::cout << line << std::endl;
			i++;
			if (!line.empty() && !_parseLine(line, this->map, ',')) {
				throw std::runtime_error(YELLOW "Invalid data format (date,value)" RESET);
			}
		}
    }
    catch (std::exception &e) {
        std::cerr <<
            RED "Error: " << fileName
            << ": line " << i << ": " << e.what()
			<< "\n\t[" << line << "]"
        << std::endl;
        return (EXIT_FAILURE);
    }
    //printMap(this->map);
	infileDB.close();
	return (EXIT_SUCCESS);
}

float	BitcoinExchange::findClosest(std::string &targetDate) const
{
	std::map<std::string, float>::const_iterator it = this->map.begin();
	float	closest = 0;

	while (it != this->map.end()) {
		if (targetDate < it->first) {
			break;
		}
		closest = it->second;
		it++;
	}
	return (closest);
}

void BitcoinExchange::convertValue(const std::string &fileName)
{
    std::ifstream infile(fileName.c_str());
    if (!infile.is_open()) {
        std::cerr << "Could not open input file, check permissions" << std::endl;
        return;
    }

    std::string line;
	if (!std::getline(infile, line)) {
        throw std::invalid_argument(YELLOW "Error: File is empty or could not read the first line" RESET);
    }
    while (std::getline(infile, line)) {
        if (line.empty()) continue;

        try {
            float value = 0;
			std::string date;

			size_t pos = line.find('|');
    		if (pos != std::string::npos) {
        		date = line.substr(0, pos - 1);
				std::string strVal = line.substr(pos + 1);
				if (strVal.empty()) {
					throw std::out_of_range(VALUE_OUT_OF_RANGE);
				}
				value = atof(strVal.c_str());
    		}
			if (_isCorrectDate(date) == false) {
				throw std::invalid_argument(INVALID_DATA);
			}
            float rate = this->findClosest(date);
			if (value < 0 || value > 1000) {
            	throw std::out_of_range(VALUE_OUT_OF_RANGE);
        	}
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << "\n\tProblematic Line: " << line << std::endl;
        }
    }
    infile.close();
}

const char *BitcoinExchange::NegativeNumber::what() const throw()
{
	return (YELLOW "Not a positive number." RESET);
}

const char *BitcoinExchange::TooLargeNumber::what() const throw()
{
	return (YELLOW "Too large a number." RESET);
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << RED
		"BitcoinExchange Destructor is called"
	RESET << std::endl;
}