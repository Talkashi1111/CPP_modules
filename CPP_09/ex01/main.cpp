#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: usage: " << argv[0] << " <expression>" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn(argv[1]);
		return 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error " << e.what() << std::endl;
		return 1;
	}
}
