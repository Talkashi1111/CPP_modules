#include "Harl.hpp"

int main(void)
{
	Harl harl;
	std::string input_level;
	std::cout << "Enter log level: \n \tDEBUG \n \tINFO \n \tWARNING \n \tERROR \n";
	std::cin >> input_level;
	harl.complain(input_level);
	return 0;
}

