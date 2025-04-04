#include "Array.hpp"
#include <iostream>
#include <sstream>
#include <limits>

template <typename T>
Array<T>::Array() : array_(new T[DefaultSize_]), arraySize_(DefaultSize_)
{
	std::cout << "default constructor for Array() is called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : array_(new T[n]), arraySize_(n)
{
	std::cout << "constructor for Array(unsigned int n) is called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &that) : array_(new T[that.arraySize_]), arraySize_(that.arraySize_)
{
	std::cout << "copy constructor for Array(const Array &that) is called" << std::endl;
	for (unsigned int i = 0; i < this->arraySize_; i++)
	{
		array_[i] = that.array_[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &that)
{
	std::cout << "operator= for Array &that is called" << std::endl;
	if (this != &that)
	{
		delete[] array_;
		this->array_ = new T[that.arraySize_];
		this->arraySize_ = that.arraySize_;
		for (unsigned int i = 0; i < this->arraySize_; i++)
		{
			array_[i] = that.array_[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "destructor for ~Array() is called" << std::endl;
	delete[] array_;
}

template <typename T>
const T &Array<T>::operator[](int index) const
{
	if (index < 0 || static_cast<unsigned int>(index) >= this->arraySize_)
	{
		std::ostringstream os;//helper to convert int to string for exception throw
		os << "Error: index " << index << " out of range";
		throw std::out_of_range(os.str());
	}
	return this->array_[index];
}

template <typename T>
T &Array<T>::operator[](int index)
{
	try {
	return const_cast<T &>(static_cast<const Array &>(*this)[index]);
	} catch (const std::out_of_range &e) {
		throw e;
	}
}//to see what is the difference in uses


template <typename T>
unsigned int Array<T>::size() const { return this->arraySize_; }
