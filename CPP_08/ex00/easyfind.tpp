#pragma once
//using algorithm::find function to find the value in the container
template <class T>
typename T::iterator easyfind(T &t, int val)
{
	typename T::iterator it;
	it = std::find(t.begin(), t.end(), val);
	return it;
}
//function overloading for array, this function will get as second argument the size of the array, to avoid overflow. using <class T> is similar to <typename T>
template <class T>
 T easyfind(T array, size_t size, int val)
{
	return std::find(array, array + size, val);
}
