#pragma once
#include <string>
#include <stdexcept>

class Bureaucrat
{
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

	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &that);
	~Bureaucrat();

	// gettes and setters
	std::string getName() const;
	int getGrade() const;

	// methods
	void incrementGrade();
	void decrementGrade();

private:
	const std::string name_;
	int grade_;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
