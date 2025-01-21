#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <iostream>


int main(void)
{
	try {
		// ShrubberyCreationForm tree("my_first_file_");
		Bureaucrat b("bureaucrat", 120);
		ShrubberyCreationForm tree("awsome_file_");
		AForm *f = &tree;
		std::cout << "the form is " << (f->getSigned() ? "signed" : "not signed")  << std::endl;
		b.signForm(tree);
		b.signForm(*f);
		b.executeForm(*f);
		tree.execute(b);

		std::cout << "-------------------------------------------------------------------"	<< std::endl;
		std::cout << "Tests for RobotomyRequestForm" << std::endl;
		Bureaucrat tom("Tom", 30);
		Bureaucrat jerry("Jerry", 70);
		RobotomyRequestForm robot("robot");
		tom.signForm(robot);
		tom.executeForm(robot);
		tom.executeForm(robot);

		std::cout << "-------------------------------------------------------------------"	<< std::endl;
		std::cout << "Tests for PresidentialPardonForm" << std::endl;
		PresidentialPardonForm pardon("pardon");
		std::cout << pardon << std::endl;
		Bureaucrat zaphod("Zaphod", 10);
		zaphod.incrementGrade();
		zaphod.incrementGrade();
		zaphod.incrementGrade();
		zaphod.incrementGrade();
		zaphod.incrementGrade();
		zaphod.incrementGrade();
		zaphod.signForm(pardon);
		pardon.execute(zaphod);


	}
	catch (std::exception &e)
	{
		std::cerr << e.what() ;
	}
}
