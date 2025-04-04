#pragma once
#include <iterator>
#include <iostream>
#include <algorithm>
template <class T>
typename T::iterator easyfind(T &t, int val);

template <typename T>
 T easyfind(T array, size_t size, int val);
#include "easyfind.tpp"
