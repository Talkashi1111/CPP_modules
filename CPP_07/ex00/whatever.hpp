#pragma once
#include <iostream>
template<typename T>
void swap( T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T max(T a, T b) {
	if (a > b)
		return a;
	return b;
}

template <typename T>
T min (T a, T b)
{
	if (a < b)
		return a;
	return b;
}


class Awesome
{
public:
	Awesome(int n = 4);
	Awesome(const Awesome &other) ;
	Awesome &operator=(const Awesome &other);
	~Awesome();
	std::string get_s() const;
	float get_f() const;

private:
	int _n;
	static const float _f = 42.42;
	std::string _s;
};


