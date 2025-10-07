#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		//const members must be initialized in the constructor's initializer list.
		const		std::string _name;
		bool		_isSigned;
		const int	_gradeToSign;
		const int	_gradeToExecute;

	public:
		Form();
		Form(const Form& obj) = default;
		Form& operator=(const Form& obj) = delete; // Assignment is not allowed due to const members
		~Form() = default;
		//Use explicit to prevent implicit conversions.
		explicit Form(const std::string& name, int gradeToSign, int gradeToExecute);

		// Getters for private attributes
		const std::string& getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& b);

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

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
