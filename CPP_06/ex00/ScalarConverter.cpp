#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <limits>
#include <iomanip>
#include <stdexcept>
#include <cerrno>
#include <cstdlib>


enum Type{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	IMPOSSIBLE
};

ScalarConverter::ScalarConverter() { std::cout << "Default constructor called" << std::endl; }
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &that)
{
	(void)that;
	return (*this);
}

ScalarConverter::~ScalarConverter() { std::cout << "default destructor called " << std::endl; }


bool convertChar(std::string &value)
{
	char c = value[0];
	std::cout << "char : '" << c << "'" << std::endl;
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float : " << static_cast<float>(c) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double : " << static_cast<double>(c) << std::endl;
	return (true);
}

bool ft_isprint(long long num)
{
	if (num < 32 || num > 126)
		return (false);
	return (true);
}

bool convertInt(std::string &value)
{
	char *endptr = NULL;
	errno = 0;
	long num = strtol(value.c_str(), &endptr, 10);
	if (errno || *endptr != '\0' || num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
	{
		std::cout << "Error input: impossible to convert" << std::endl;
		return (false);
	}
	int x = static_cast<int>(num);
	if (!ft_isprint((long long)num))
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(x) << "'" << std::endl;
	std::cout << "int : " << x << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float : " << static_cast<float>(x) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double : " << static_cast<double>(x) << std::endl;
	return (true);
}

bool convertFloat(std::string &value)
{
	float f;
	double d;
	char c;
	int i;
	char *endptr = NULL;
	if (value == "-inff" || value == "+inff")
	{
		if (value[0] == '-')
			f = -std::numeric_limits<float>::infinity();
		else
			f = std::numeric_limits<float>::infinity();
		d = static_cast<double>(f);
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << f << "f" << std::endl;
		std::cout << "double : " << d << std::endl;
		return (true);
	}
	if (value == "nanf")
	{
		f = std::numeric_limits<float>::quiet_NaN();
		d = static_cast<double>(f);
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << f << "f" <<std::endl;
		std::cout << "double : " << d << std::endl;
		return (true);
	}

	errno = 0;
	f = std::strtof(value.c_str(), &endptr);
	if (errno || !endptr || *endptr != 'f')
	{
		std::cout << "Error input: impossible to convert" << std::endl;
		return (false);
	}
	size_t printable = value.length() - value.find('.') - 2;
	d = static_cast<double>(f);
	c = static_cast<char>(f);
	i = static_cast<int>(f);
	if (!ft_isprint(c))
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : '" << c << "'" << std::endl;
	std::cout << "int : " << i << std::endl;
	/* if (value.substr(value.length() - 3, 3) == ".0f")
		std::cout << std::fixed << std::setprecision(1) << "float : " << f << "f" << std::endl; */
	std::cout << std::fixed << std::setprecision(printable) << "float : " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double : " << d << std::endl;
	return (true);
}

bool convertDouble(std::string &str)
{
	double d;
	char c;
	int i;
	char *endptr = NULL;
	if (str == "-inf" || str == "+inf")
	{
		if (str[0] == '-')
			d = -std::numeric_limits<double>::infinity();
		else
			d = std::numeric_limits<double>::infinity();
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double : " << d << std::endl;
		return (true);
	}
	if (str == "nan")
	{
		d = std::numeric_limits<double>::quiet_NaN();
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double : " << d << std::endl;
		return (true);
	}
	errno = 0;
	d = std::strtod(str.c_str(), &endptr);
	if (errno || !endptr || *endptr != '\0')
	{
		std::cout << "Error input: impossible to convert" << std::endl;
		return (false);
	}
	c = static_cast<char>(d);
	i = static_cast<int>(d);
	if (!ft_isprint(c))
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : '" << c << "'" << std::endl;
	std::cout << "int : " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float : " << static_cast<float>(d) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double : " << d << std::endl;
	return (true);

}

int getType(std::string &str)
{
	int cntDot = 0;
	int cntF = 0;
	int cntLeft = 0;
	int cntRight = 0;
	size_t i = 0;

	if (str.length() == 1  && !isdigit(str[0]) && isprint(str[0]))
		return(CHAR);
	if (str == "-inf" || str == "+inf" || str == "nan")
		return DOUBLE;
	else if (str == "-inff" || str == "+inff" || str == "nanf")
		return FLOAT;

	if (str[0] == '+' || str[0] == '-')
		i++;
	for (; i < str.length(); i++)
	{
		if (isdigit(str[i]) && cntDot != 0)
			cntRight++;
		else if (str[i] == '.')
			cntDot++;
		else if (str[i] == 'f')
			cntF++;
		else if (isdigit(str[i]))
			cntLeft++;
		else
			return IMPOSSIBLE;
	}
	if (cntDot == 0 && cntF == 0)
		return INT;
	else if (cntLeft > 0 && cntDot == 1 && cntRight > 0 && cntF == 0)
			return DOUBLE;
	else if (cntLeft > 0 && cntDot == 1 && cntRight > 0 && cntF == 1 && str[str.length() - 1] == 'f')
		return FLOAT;
	else
		return IMPOSSIBLE;
}


int ScalarConverter::convert( std::string &str){
	if (str.empty())
	{
		std::cout << "Error input: empty string" << std::endl;
		return false;
	}
	int type = getType(str);
	switch (type)
	{
		case CHAR:
			return (convertChar(str));
		case INT:
			return (convertInt(str));
		case FLOAT:
			return (convertFloat(str));
		case DOUBLE:
			return (convertDouble(str));
		case IMPOSSIBLE:
			std::cout << "Error input: impossible to convert" << std::endl;
			return IMPOSSIBLE;
		default:
			break;
	}
	return (false);

}
