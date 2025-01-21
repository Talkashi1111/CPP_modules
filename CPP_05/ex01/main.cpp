#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
int main()
{
	try
	{
		// Bureaucrat jason("Jason", 160);
		Bureaucrat jason("Jason", 140);
		Form forms[4] = {Form("mutual agreement", 10, 20), Form("contract", 5, 10),
						 Form("insurance", 1, 5), Form("taxes", 1, 1)};
		for (int i = 0; i < 4; i++)
		{
			std::cout << forms[i];
		}
		for (int i = 0; i < 4; i++)
		{
			jason.signForm(forms[i]);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	/* 	try
		{
			Bureaucrat b("b", 1);
			Form f("f", 1, 1);
			b.signForm(f);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		} */
	return 0;
}
