#include "BitcoinExchange.hpp"
#include <fstream>
#include <exception>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
	ParseDb();
	std::cout << "Data parsed successfully" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	data = obj.data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
	{
		data = obj.data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::IsValidDate(const std::string &date)
{
	// Check basic length and delimiter positions
	if (date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Error: basic length and delimiter positions => " << date << std::endl;
		return false;
	}

	// Check year (0-4)
	for (int i = 0; i < 4; i++)
		if (!isdigit(date[i]))
		{
			std::cerr << "Error: year is not a digit => " << date << std::endl;
			return false;
		}

	// Check month (5-6)
	for (int i = 5; i < 7; i++)
		if (!isdigit(date[i]))
		{
			std::cerr << "Error: month is not a digit => " << date << std::endl;
			return false;
		}

	// Check day (8-9)
	for (int i = 8; i < 10; i++)
		if (!isdigit(date[i]))
		{
			std::cerr << "Error: day is not a digit => " << date << std::endl;
			return false;
		}

	// Extract and validate values
	int year = atoi(date.substr(0, 4).c_str());
	if (year < 1)
	{
		std::cerr << "Error: year is not valid => " << date << std::endl;
		return false;
	}

	int month = atoi(date.substr(5, 2).c_str());
	if (month < 1 || month > 12)
	{
		std::cerr << "Error: month is not valid => " << date << std::endl;
		return false;
	}

	int day = atoi(date.substr(8, 2).c_str());
	if (day < 1)
	{
		std::cerr << "Error: day is not valid => " << date << std::endl;
		return false;
	}

	// Month-specific day validation
	static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		if (day > 29)
		{
			std::cerr << "Error: day is not valid, not a leap year => " << date << std::endl;
			return false;
		}
	}
	else if (day > days[month])
	{
		std::cerr << "Error: day is not valid => " << date << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::ParseDb()
{
	std::ifstream file(DB);
	if (!file.is_open())
		throw std::ios_base::failure("Error: could not open file");

	std::string line;
	if (!std::getline(file, line) || line != "date,exchange_rate")
		throw std::runtime_error("Error: invalid header");

	while (std::getline(file, line))
	{
		if (line.size() < 11 || line[10] != ',')
			continue;
		std::string date = line.substr(0, 10);
		if (!IsValidDate(date))
			continue;
		float exchange_rate;
		std::istringstream stream(line.substr(11));
		stream >> exchange_rate;
		if (stream.peek() != EOF)
		{
			std::cerr << "Error: exchange rate not valid => " << line << std::endl;
			continue;
		}
		data[date] = exchange_rate;
	}
}

void BitcoinExchange::PrintRate(std::map<std::string, float>::iterator it, float value, std::string &date)
{
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

void BitcoinExchange::CalculateCurrentRate(const char *str)
{
	std::ifstream file(str);
	if (!file.is_open())
		throw std::ios_base::failure("Error: could not open file " + std::string(str));

	std::string line;
	if (!std::getline(file, line) || line != "date | value")
		throw std::runtime_error("Error: invalid header");

	while (std::getline(file, line))
	{
		if (line.size() < 13 || line.substr(10, 3) != " | ")
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, 10);
		if (!IsValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		float value;
		std::istringstream stream(line.substr(13));
		stream >> value;
		if (stream.peek() != EOF)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		else if (value < 0)
		{
			std::cerr << "Error: not a positive number" << std::endl;
			continue;
		}
		else if (value > 1000)
		{
			std::cerr << "Error: too large number" << std::endl;
			continue;
		}
		std::map<std::string, float>::iterator it = data.lower_bound(date);
		if (it == data.end())
		{
			std::cout << "No data available for this date" << std::endl;
			continue;
		}
		else
		{
			PrintRate(it, value, date);
		}
	}
}
