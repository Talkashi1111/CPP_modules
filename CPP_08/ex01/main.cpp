#include <vector>
#include "Span.hpp"
#include <iostream>

int main()
{
	try {
		Span sp(10);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(-12);
		sp.addNumber(9);
		sp.addNumber(0);
		std::vector<int> v = sp.getData();
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		Span sp2(10000000);
		std::vector<int> v2(10000, 0);
		sp2.addNumbers(v2.begin(), v2.end());
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}



}
