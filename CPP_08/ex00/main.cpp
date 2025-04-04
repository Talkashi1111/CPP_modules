#include <vector>
#include <list>
#include <iostream>
#include "easyfind.hpp"


int main(void)
{
	std::vector<int> first(4, 100);
	std::vector<int> second(first.begin(), first.end());

	int myints[] = {16, 22, 31, 9844, -2};
	std::vector<int> third(myints, myints + sizeof(myints) / sizeof(int));

	std::cout << "the content of the third are: " << std::endl;
	for (std::vector<int>::iterator it = third.begin(); it != third.end(); it++)
		std::cout << " " << *it << std::endl;

	std::cout<< "\n\nsearching in the third" << std::endl;
	std::vector<int>::iterator it = easyfind(third, 31);
	if (it != third.end())
		std::cout << "the value of 31 is found at: " << *it << " &it is "<< &it<<std::endl;
	else
		std::cout << "the value of 31 is not found, &it is "<< &it  << " *it is " << *it << std::endl;
	int *p;
	p = easyfind(myints, size_t(sizeof(myints) / sizeof(int)), 31);
	if (p != myints + sizeof(myints) / sizeof(int))
		std::cout << "the value of 31 is found at: " << *p << std::endl;
	else
		std::cout << "the value of 31 is not found, &p is "<< &p  << " *p is " << *p << std::endl;


	std::cout << "try to find value of 100 in the third" << std::endl;
	it = easyfind(third, 100);
	std::cout << "the value of 100 is found at: " << *it << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::list<int> lst(myints, myints + sizeof(myints) / sizeof(int));
	std::cout << "try to find value of 31 in the lst" << std::endl;
	std::list<int>::iterator it2 = easyfind(lst, 31);
	std::cout << "the value of 31 is found at: " << *it2 << std::endl;
	std::cout << "try to find value of 100 in the lst" << std::endl;
	it2 = easyfind(lst, 100);
	if (it2 == lst.end())
		std::cout << "the value of 100 is not found" << std::endl;
	else
		std::cout << "the value of 100 is found at: " << *it2 << std::endl;

	int myints2[] = {31, -222, 133, 9844, -1, 2, 99};
	std::list<int> lst2(myints2, myints2 + sizeof(myints2) / sizeof(int));
	for (std::list<int>::iterator it = lst2.begin(); it != lst2.end(); it++)
		std::cout << " " << *it << std::endl;
	std::cout << "try to find value of 100 in the lst2" << std::endl;
	it2 = easyfind(lst2, 100);
	if (it2 == lst2.end())
		std::cout << "the value of 100 is not found" << std::endl;
	else
		std::cout << "the value of 100 is found at: " << *it2 << std::endl;
	std::cout << " try to find value 9844 in the lst2" << std::endl;
	it2 = easyfind(lst2, 9844);
	if (it2 == lst2.end())
		std::cout << "the value of 9844 is not found" << std::endl;
	else
		std::cout << "the value of 9844 is found at: " << *it2 << std::endl;

	return 0;
}
