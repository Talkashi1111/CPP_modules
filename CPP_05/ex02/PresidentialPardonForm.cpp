#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target_(target)
{
	std::cout << "PresidentialPardonForm constructor for " << this->target_ << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target_(other.target_)
{
	std::cout << "PresidentialPardonForm copy constructor for " << this->target_ << std::endl;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &that)
{
	if (this != &that)
	{
		this->target_ = that.target_;
		AForm::operator=(that);
	}
	std::cout << "PresidentialPardonForm assignation operator for " << this->target_ << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor for " << this->target_ << std::endl;
}

int PresidentialPardonForm::execute(const Bureaucrat &b) const
{
	try {
			isExecutable(b);
			std::cout << this->target_ << " got pardoned by Zaphod Beeblebrox" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
		return false;
	}
	return true;
}
