#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	checkExecution(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}