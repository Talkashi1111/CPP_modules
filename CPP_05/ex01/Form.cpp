#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
Form::Form(std::string name, int to_sign, int to_ex) : name_(name), GradeToSign_(to_sign), GradeToEx_(to_ex)
{
	if (to_sign < 1 || to_ex < 1)
	{
		std::cout << "Form constructor failed for " << this->name_ << std::endl;
		throw GradeTooHighException("Form::GradeTooHighException for " +this->name_);
	}
	if (to_sign > 150 || to_ex > 150)
	{
		std::cout << "Form constructor failed for " << this->name_ << std::endl;
		throw GradeTooLowException("Form::GradeTooLowException for " +this->name_);//to see if needed to call a destructor in the main because in this point the object is allready build
	}
	this->signed_ = false;
	std::cout << "Form constructor for " << this->getName() << std::endl;;
}

Form::Form(const Form &other) : name_(other.name_), GradeToSign_(other.GradeToSign_), GradeToEx_(other.GradeToEx_)
{
	this->signed_ = other.signed_;
	if (this->GradeToSign_ > 150 || this->GradeToEx_ > 150)
	{
		std::cout << "Form copy constructor failed for " << this->name_ << std::endl;
		throw GradeTooLowException(this->name_);
	}
	else if (this->GradeToSign_ < 1 || this->GradeToEx_ < 1)
	{
		std::cout << "Form copy constructor failed for " << this->name_ << std::endl;
		throw GradeTooHighException(this->name_);
	}
	std::cout << "Form copy constructor for " << this->getName() << std::endl;;
}

Form &Form::operator=(const Form &that)
{
	if (this != &that)
	{
		this->signed_ = that.signed_;
	}
	std::cout << "Form assignation operator for " << this->getName() << std::endl;
	return (*this);
}


Form::~Form()
{
	std::cout << "Form destructor for " << this->getName() << std::endl;;
}


//getters
std::string Form::getName() const { return this->name_; }
bool Form::getSigned() const { return this->signed_; }
int Form::getGradeToSign() const { return this->GradeToSign_; }
int Form::getGradeToEx() const { return this->GradeToEx_; }

//operators overloading
std::ostream &operator<<(std::ostream &out, const Form &form)
{
	return out << "Form " << form.getName() << " has a grade to sign "<< form.getGradeToSign() << " a grade to excecute " << form.getGradeToEx() << " and is " << (form.getSigned() ? "signed" : "not signed") << ".\n";
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException("Form::GradeTooLowException throw from " + this->getName() + "\n");
	this->signed_ = true;
}

//exceptions constructors
Form::GradeTooHighException::GradeTooHighException(const std::string msg) : std::range_error(msg) {}

Form::GradeTooLowException::GradeTooLowException(const std::string msg) : std::range_error(msg) {}
