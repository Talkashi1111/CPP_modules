#pragma once

#include <iostream>
#include <string>
#include <map>
#include <functional>

#define DB "data.csv"

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &obj);
	BitcoinExchange &operator=(const BitcoinExchange &obj);
	~BitcoinExchange();

	//TODO: who is in private?
	void CalculateCurrentRate(const char *file);
	void PrintRate(std::map<std::string, float>::iterator it, float quantity, std::string &date);

private:
	void ParseDb();
	bool IsValidDate(const std::string& date);

	std::map<std::string, float, std::greater<std::string> > data;
};
