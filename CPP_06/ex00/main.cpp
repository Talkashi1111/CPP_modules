#include <stdio.h>
#include <string>
#include <iostream>
#include "ScalarConverter.hpp"


int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		std::string str(argv[1]);
		return(ScalarConverter::convert(str));
	}
	std::cout << "Error: use with only one argument" <<std::endl;
	return (0);
}
