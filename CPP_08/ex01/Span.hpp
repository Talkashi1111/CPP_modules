#pragma once
#include <vector>
#include <iterator>
#include <iostream>
#include <exception>
#include <algorithm>
#include <limits>

class Span
{
public:
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
	void addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last);
	void addNumbers(int elements, int value);

	// getters
	std::vector<int> getData() const;

private:
	std::vector<int> data_;
	int maxNum_;
	int minNum_;
	int minDiff_;
};



