#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=== Bureaucrat Grade Boundary Tests ===" << std::endl;
	try
	{
		Bureaucrat ONE("ONE", 1);
		std::cout << ONE << std::endl;
		std::cout << "Attempting to increment grade (should throw):" << std::endl;
		ONE.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat TWO("TWO", 150);
		std::cout << TWO << std::endl;
		std::cout << "Attempting to decrement grade (should throw):" << std::endl;
		TWO.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Form Creation Exception Test ===" << std::endl;
	try
	{
		std::cout << "Attempting to create invalid form (should throw):" << std::endl;
		Form invalid("InvalidForm", 0, 151);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Form Signing Tests ===" << std::endl;
	Bureaucrat ONE("ONE", 50);
	Bureaucrat TWO("TWO", 140);
	Form formA("FormA", 100, 50);
	Form formB("FormB", 130, 50);

	std::cout << ONE << std::endl;
	std::cout << TWO << std::endl;
	std::cout << formA << std::endl;
	std::cout << formB << std::endl;

	std::cout << "\nONE tries to sign FormA (should succeed):" << std::endl;
	ONE.signForm(formA);

	std::cout << "\nTWO tries to sign FormA (should fail):" << std::endl;
	TWO.signForm(formA);

	std::cout << "\nTWO tries to sign FormB (should succeed):" << std::endl;
	TWO.signForm(formB);

	std::cout << "\nFinal form statuses:" << std::endl;
	std::cout << formA << std::endl;
	std::cout << formB << std::endl;

	return 0;
}

