#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
    Intern someRandomIntern;
    AForm *rrf = NULL;
    AForm *shrub = NULL;
    AForm *pres = NULL;
    AForm *wrong = NULL;

    try
    {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        shrub = someRandomIntern.makeForm("shrubbery creation", "Bender");
        pres = someRandomIntern.makeForm("presidential pardon", "Bender");
        wrong = someRandomIntern.makeForm("", "Bender");  // This will likely throw

        std::cout << *rrf << std::endl;
        std::cout << *shrub << std::endl;
        std::cout << *pres << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Delete the successfully allocated forms
    delete pres;//even if NULL its ok
    delete shrub;
    delete rrf;
	delete wrong;
	return 0;
}
