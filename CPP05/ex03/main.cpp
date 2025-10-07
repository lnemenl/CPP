#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "=== Intern, Bureaucrat, and Form Demonstration ===\n" << std::endl;

    try
    {
        Bureaucrat ONE("ONE", 1);
        Bureaucrat TWO("TWO", 140);

        Intern someRandomIntern;

        std::cout << "\n--- Intern creates forms ---" << std::endl;
        AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "Tree");
        AForm* robot = someRandomIntern.makeForm("robotomy request", "RD2D");
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "LORD BECKETT");

        std::cout << "\n--- TWO tries to sign and execute ShrubberyCreationForm ---" << std::endl;
        TWO.signForm(*shrub);
        TWO.executeForm(*shrub);

        std::cout << "\n--- ONE signs and executes all forms ---" << std::endl;
        ONE.signForm(*shrub);
        ONE.executeForm(*shrub);

        ONE.signForm(*robot);
        for (int i = 0; i < 3; ++i)
		{
            std::cout << "Robotomy attempt " << (i + 1) << ": ";
            ONE.executeForm(*robot);
        }

        ONE.signForm(*pardon);
        ONE.executeForm(*pardon);

        std::cout << "\n--- Intern tries to create an unknown form ---" << std::endl;
        try
		{
            AForm* unknown = someRandomIntern.makeForm("unknown form", "Nobody");
            delete unknown;
        }
		catch (const std::exception& e)
		{
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }

        delete shrub;
        delete robot;
        delete pardon;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    std::cout << "\n=== End of Demonstration ===" << std::endl;
    return 0;
}