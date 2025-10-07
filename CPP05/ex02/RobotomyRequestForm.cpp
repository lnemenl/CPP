#include "RobotomyRequestForm.hpp"
#include <cstdlib> // For rand(), srand()
#include <ctime> // For time()

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    :AForm("RobotomyRequestForm", 72, 45), _target(target) {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    checkExecution(executor);

    std::cout << "Drilling noises" << std::endl;

    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(0)); // Seeding the value that changes(time is seconds) to get different sequence each run
        seeded = true;
    }
    
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy of " << _target << " faield." <<std::endl;
}

//std::srand() seeds the random number generator.
//std::rand() is a C standard library function that returns a pseudo-random integer.