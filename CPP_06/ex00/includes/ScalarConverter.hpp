#pragma once
#include <string>

class ScalarConverter{
	public:
	//method
	static int convert(std::string &value);

	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter &operator=(const ScalarConverter &);
	virtual ~ScalarConverter();
};
