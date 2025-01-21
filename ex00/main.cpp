#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: must have one argument of txt file" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange my_exchange;
		my_exchange.CalculateCurrentRate(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
