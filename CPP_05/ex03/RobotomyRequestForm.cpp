#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target_(target)
{
	std::cout << "RobotomyRequestForm constructor for " << this->getName() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target_(other.target_)
{
	std::cout << "RobotomyRequestForm copy constructor for " << this->getName() << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &that)
{
	if (this != &that)
	{
		this->target_ = that.target_;
	}
	std::cout << "RobotomyRequestForm assignation operator for " << this->getName() << std::endl;
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor for " << this->getName() << std::endl;
}
void RobotomyRequestForm::Robotomize() const
{
	srand(time(NULL));
	if (rand() % 2)
	{
		std::cout << "Robotomize " << this->target_ << " has been successful" << std::endl;
	}
	else
	{
		throw RobotomizeFailedException("Robotomize " + this->target_ + " has failed");
	}
}

RobotomyRequestForm::RobotomizeFailedException::RobotomizeFailedException(const std::string msg) : std::logic_error(msg) {}

int RobotomyRequestForm::execute(const Bureaucrat &b) const
{
	try
	{
		isExecutable(b);
		std::cout << "Oupzzzzziii" << std::endl;
		Robotomize();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return false;
	}
	return true;
}
