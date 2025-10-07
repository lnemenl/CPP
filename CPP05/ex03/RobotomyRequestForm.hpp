#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		//const because a form's target shouldn't change after creation
		const std::string _target;
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm&) = default;
		RobotomyRequestForm& operator=(const RobotomyRequestForm&) = delete;
		~RobotomyRequestForm() = default;
		RobotomyRequestForm() = delete;
		void execute(Bureaucrat const& executor) const override;
};

#endif