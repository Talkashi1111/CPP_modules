#pragma once
#include <stack>
#include <deque>
#include <iostream>
#include <iterator>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack();
	MutantStack(MutantStack const &other);
	MutantStack &operator=(MutantStack const &other);
	~MutantStack();
	typedef typename Container::iterator iterator;
	iterator end();
	iterator begin();
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{
	std::cout << "MutantStack created" << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack const &other) : std::stack<T, Container>(other)
{
	std::cout << "MutantStack copy constructor called" << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(MutantStack const &other)
{
	std::cout << "MutantStack copy assignation called" << std::endl;
	if (this != &other)
		*this = other;
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
	std::cout << "MutantStack destroyed" << std::endl;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return (this->c.end());
}
