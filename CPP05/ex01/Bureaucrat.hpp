#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;
class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& obj) = default;
		Bureaucrat& operator=(const Bureaucrat& obj) = delete; // Assignment is not allowed due to const members
		~Bureaucrat() = default;
		// Parameterized constructor
		explicit Bureaucrat(const std::string& name, int grade);

		//const reference for string to avoid copy, const for method to promise no modification.
		const std::string& getName() const;
		int getGrade() const; //The const at the end means this function does NOT modify any member variables of the object AND I can call this function on const objects.

		//These methods change the grade, so not const.
		void incrementGrade();
		void decrementGrade();

		void signForm(Form& form); // Pass by reference to modify the Form

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
