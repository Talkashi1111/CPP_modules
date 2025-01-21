#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
AForm::AForm(std::string name, int to_sign, int to_ex) : name_(name), GradeToSign_(to_sign), GradeToEx_(to_ex)
{
	if (to_sign < 1 || to_ex < 1)
	{
		std::cout << "AForm constructor failed for " << this->name_ << std::endl;
		throw GradeTooHighException("AForm::GradeTooHighException for " +this->name_);
	}
	if (to_sign > 150 || to_ex > 150)
	{
		std::cout << "AForm constructor failed for " << this->name_ << std::endl;
		throw GradeTooLowException("AForm::GradeTooLowException for " +this->name_);
	}
	this->signed_ = false;
	std::cout << "AForm constructor for " << this->getName() << std::endl;;
}

AForm::AForm(const AForm &other) : name_(other.name_), GradeToSign_(other.GradeToSign_), GradeToEx_(other.GradeToEx_)
{
	this->signed_ = other.signed_;
	if (this->GradeToSign_ > 150 || this->GradeToEx_ > 150)
	{
		std::cout << "AForm copy constructor failed for " << this->name_ << std::endl;
		throw GradeTooLowException(this->name_);
	}
	else if (this->GradeToSign_ < 1 || this->GradeToEx_ < 1)
	{
		std::cout << "AForm copy constructor failed for " << this->name_ << std::endl;
		throw GradeTooHighException(this->name_);
	}
	std::cout << "AForm copy constructor for " << this->getName() << std::endl;;
}

AForm &AForm::operator=(const AForm &that)
{
	if (this != &that)
	{
		this->signed_ = that.signed_;
	}
	std::cout << "Form assignation operator for " << this->getName() << std::endl;
	return (*this);
}


AForm::~AForm()
{
	std::cout << "AForm destructor for " << this->getName() << std::endl;;
}


//getters
std::string AForm::getName() const { return this->name_; }
bool AForm::getSigned() const { return this->signed_; }
int AForm::getGradeToSign() const { return this->GradeToSign_; }
int AForm::getGradeToEx() const { return this->GradeToEx_; }

//operators overloading
std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	return out << "AForm " << form.getName() << " has a grade to sign "<< form.getGradeToSign() << " a grade to excecute " << form.getGradeToEx() << " and is " << (form.getSigned() ? "signed" : "not signed") ;
}

void AForm::isExecutable(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToEx())
		throw AForm::GradeTooLowException("Form::GradeTooLowException throw from " + this->getName() + "\n");
	if (!this->getSigned())
	{
		throw AForm::IsNotSignedException("Form::IsNotSignedException throw from " + this->getName() + "\n");
	}
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException("Form::GradeTooLowException throw from " + this->getName() + "\n");
	this->signed_ = true;
}

//exceptions constructors
AForm::GradeTooHighException::GradeTooHighException(const std::string msg) : std::range_error(msg) {}

AForm::GradeTooLowException::GradeTooLowException(const std::string msg) : std::range_error(msg) {}
AForm::IsNotSignedException::IsNotSignedException(const std::string msg) : std::range_error(msg) {}
AForm::IsAlreadySignedException::IsAlreadySignedException(const std::string msg) : std::range_error(msg) {}
