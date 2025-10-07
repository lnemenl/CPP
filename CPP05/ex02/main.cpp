#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "=== Bureaucrat and Form Demonstration ===\n" << std::endl;

    try
	{
        Bureaucrat ONE("ONE", 1);
        Bureaucrat TWO("TWO", 137); //140
        Bureaucrat THREE("THREE", 50);

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("RD2D");
        PresidentialPardonForm pardon("LORD BECKETT");

        std::cout << "\n--- TWO tries to sign and execute ShrubberyCreationForm ---" << std::endl;
        std::cout << "TWO tries to sign (should succeed):" << std::endl;
        TWO.signForm(shrub);
        std::cout << "TWO tries to execute (should fail: grade too low):" << std::endl;
        TWO.executeForm(shrub);

        std::cout << "\n--- ONE signs and executes RobotomyRequestForm ---" << std::endl;
        ONE.signForm(robot);
		std::cout << "\n--- ONE signs and executes RobotomyRequestForm multiple times (should see random results) ---" << std::endl;
		ONE.signForm(robot);
		for (int i = 0; i < 5; ++i)
		{
    		std::cout << "Attempt " << (i + 1) << ": ";
    		ONE.executeForm(robot);
		}
        ONE.executeForm(robot);

        // std::cout << "\n--- TWO signs and executes RobotomyRequestForm multiple times (should see random results) ---" << std::endl;
		// TWO.signForm(shrub);
		// for (int i = 0; i < 5; ++i)
		// {
    	// 	std::cout << "Attempt " << (i + 1) << ": ";
    	// 	TWO.executeForm(shrub);
		// }

        std::cout << "\n--- ONE signs and executes PresidentialPardonForm ---" << std::endl;
        ONE.signForm(pardon);
        ONE.executeForm(pardon);

        std::cout << "\n--- THREE tries to sign and execute RobotomyRequestForm ---" << std::endl;
        THREE.signForm(robot);   // Should fail
        THREE.executeForm(robot);

        std::cout << "\n--- ONE executes ShrubberyCreationForm (should succeed) ---" << std::endl;
        ONE.executeForm(shrub);

        std::cout << "\n--- ONE tries to execute an unsigned ShrubberyCreationForm ---" << std::endl;
        ShrubberyCreationForm notSigned("yard");
        ONE.executeForm(notSigned);

    }
	catch (const std::exception& e)
	{
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    std::cout << "\n=== End of Demonstration ===" << std::endl;
    return 0;
}