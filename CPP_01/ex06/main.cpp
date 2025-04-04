#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return false;
	}
	Harl harl;
	std::string input_level = argv[1];
	harl.complain(input_level);
	return true;
}
