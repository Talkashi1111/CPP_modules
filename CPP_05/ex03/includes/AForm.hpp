#pragma once
#include <stdexcept>
#include <string>
class Bureaucrat;

class AForm{

public:

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
	class IsNotSignedException : public std::range_error
	{
		public:
			IsNotSignedException(const std::string msg);
	};
	class IsAlreadySignedException : public std::range_error
	{
		public:
			IsAlreadySignedException(const std::string msg);
	};// maybe not needed

	AForm(std::string name, int to_sign, int to_ex);
	AForm (const AForm &other);
	AForm &operator=(const AForm &that);
	virtual ~AForm();


	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToEx() const;

	void beSigned(const Bureaucrat &b);
	virtual int execute(const Bureaucrat &b) const = 0;
protected:
	void isExecutable(const Bureaucrat &executor) const;
private:
	const std::string name_;
	bool signed_;
	const int GradeToSign_;
	const int GradeToEx_;
};


std::ostream &operator<<(std::ostream &out, const AForm &f);
