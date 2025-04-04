#pragma once
#include <iostream>
#include <iterator>

template <typename T>
void addedOneNprint(T &array);

template <typename T, typename Func>
void iter(T arr[], size_t size, Func func)
{
	std::cout << "At Iter" << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		func(arr[i]);
	}
}

