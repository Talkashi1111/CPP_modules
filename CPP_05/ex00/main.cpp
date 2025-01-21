#include "Bureaucrat.hpp"
#include <iostream>
int main(void)
{
	try
	{
		Bureaucrat b1("Tom", 147);
		Bureaucrat b2("Jerry", 3);
		std::cout << b1;
		std::cout << b2;
		b2 = b1;
		std::cout << "After assignation now the grade of Jerry will be the same as Tom" << std::endl;
		std::cout << b2;
		b1.decrementGrade();
		b1.decrementGrade();
		b1.decrementGrade();

		Bureaucrat b3("Putin", 3);
		std::cout << b3;
		b3.incrementGrade();
		b3.incrementGrade();
		Bureaucrat tooHigh("im_so_high", -1);
	}
	catch (std::exception &e)
	{
		std::cout << "got exception: " << e.what() << std::endl;
	}
/* 	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "got GradeTooHighException: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "got GradeTooLowException: " << e.what() << std::endl;
	} */
}
