#pragma once
#include <stdexcept>
#include <time.h>
#include <stdlib.h>

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array &a);
	Array &operator=(const Array &that);
	~Array();

	// operator overloading : throw out of range
	const T &operator[](int index) const;
	T &operator[](int index);

	// member function
	unsigned int size() const;

private:
	T *array_;
	unsigned int arraySize_;
	static const unsigned int DefaultSize_ = 14;
};

#include "Array.tpp"
