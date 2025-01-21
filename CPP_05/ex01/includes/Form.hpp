#pragma once
#include <stdexcept>
#include <string>
class Bureaucrat;

class Form{

public:
	Form(std::string name, int to_sign, int to_ex);
	Form (const Form &other);
	Form &operator=(const Form &that);
	~Form();


	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToEx() const;

	class GradeTooHighException : public std::range_error
	{
	public:
		GradeTooHighException(const std::string msg);
	};

	class GradeTooLowException : public std::range_error
	{
	public:
		GradeTooLowException(const std::string msg);
	};

	void beSigned(const Bureaucrat &b);

private:
	const std::string name_;
	bool signed_;
	const int GradeToSign_;
	const int GradeToEx_;
};


std::ostream &operator<<(std::ostream &out, const Form &form);
