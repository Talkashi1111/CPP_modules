#include "Bureaucrat.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name)
{
	if (grade < 1)
	{
		std::cout << "Bureaucrat constructor failed for " << this->name_ << std::endl;
		throw GradeTooHighException("Bureaucrat::GradeTooHighException for "+ this->name_);
	}
	if (grade > 150)
	{
		std::cout << "Bureaucrat constructor failed for " << this->name_ << std::endl;
		throw GradeTooLowException("Bureaucrat::GradeTooLowException for " + this->name_);
	}
	this->grade_ = grade;
	std::cout << "Bureaucrat constructor for " << this->name_ << " with grade " << this->grade_ << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	this->grade_ = other.grade_;
	std::cout << "Bureaucrat copy constructor for " << this->name_ << " with grade " << this->grade_ << std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &that)
{
	if (this != &that)
	{
		this->grade_ = that.grade_;
	}
	std::cout << "Bureaucrat assignation operator for " << this->name_ << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor for " << this->name_ << std::endl;
}

std::string Bureaucrat::getName() const { return this->name_;}
int Bureaucrat::getGrade() const { return this->grade_;}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &B)
{
	return out << B.getName() << ", bureaucrat grade " << B.getGrade() << ".\n";
}

void Bureaucrat::incrementGrade()
{
	if (this->grade_ == 1)
		throw GradeTooHighException(this->name_);
	this->grade_--;
	std::cout << "Bureaucrat " << this->name_ << " grade incremented to " << this->grade_ << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade_ == 150)
		throw GradeTooLowException(this->name_);
	this->grade_++;
	std::cout << "Bureaucrat " << this->name_ << " grade decremented to " << this->grade_ << std::endl;
}

void Bureaucrat::signForm(AForm &f)
{
	if (f.getSigned())
	{
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because it is already signed " << std::endl;
		return;
	}
	try {
		f.beSigned(*this);
		std::cout << "Bureaucrat " << this->name_ << " signs " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat " << this->name_ << " cannot sign " << f.getName() << " because " << e.what();
	}
}


void Bureaucrat::executeForm(AForm const &form)
{
	try{
		if (!form.execute(*this))
			return;
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat " << this->name_ << " cannot execute " << form.getName() << " because " << e.what();
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string msg) : std::range_error(msg) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string msg) : std::range_error(msg) {}
