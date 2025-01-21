#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}
Intern::Intern(Intern const &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern &Intern::operator=(Intern const &other)
{
	std::cout << "Intern assign operator called" << std::endl;
	if (this != &other)
	{
		(void)other;
	}
	return *this;
}
Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

// Function to create a ShrubberyCreationForm
AForm* createShrubbery(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

// Function to create a RobotomyRequestForm
AForm* createRobotomy(std::string const &target) {
    return new RobotomyRequestForm(target);
}

// Function to create a PresidentialPardonForm
AForm* createPresidential(std::string const &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
	std::string form_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Prototypes prototypes[3] = {createShrubbery, createRobotomy, createPresidential};
	AForm *new_form = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (name == form_names[i])
		{
			try {
				new_form = prototypes[i](target);
				std::cout << "Intern creates " << name << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "Intern failed to create " << name << std::endl;
				throw Intern::UnknownFormat(e.what());
			}

		}
	}
	if (new_form == NULL)
	{
		std::cout << "Intern failed to create " << name << std::endl;
		throw Intern::UnknownFormat("Form name not found or empty");
	}
	return new_form;
}

Intern::UnknownFormat::UnknownFormat(const std::string msg) : std::invalid_argument(msg){}
