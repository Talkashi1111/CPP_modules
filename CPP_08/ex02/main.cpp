#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <list>
// can test with vecotr, list, deque and list
int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "-------------------" << std::endl;

	MutantStack<int, std::list<int> > mstack1;
	mstack1.push(120);
	mstack1.push(170);
	mstack1.push(180);
	mstack1.push(-31);

	MutantStack<int, std::list<int> >::iterator it2 = mstack1.begin();
	std::cout << *it2 << std::endl;
	MutantStack<int, std::list<int> >::iterator ite2 = mstack1.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::cout << "-------------------" << std::endl;
	MutantStack<int, std::list<int> >::iterator it3 = mstack1.begin();
	std::cout << *it3 << std::endl;

	return 0;
}
