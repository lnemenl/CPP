#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		//const members must be initialized in the constructor's initializer list.
		const		std::string _name;
		bool		_isSigned;
		const int	_gradeToSign;
		const int	_gradeToExecute;

	public:
		AForm();
		AForm(const AForm& obj) = default;
		AForm& operator=(const AForm& obj) = delete; // Cannot be assigned after construction (assignment is forbidden (const members))
		virtual ~AForm();
		//Use explicit to prevent implicit conversions.
		explicit AForm(const std::string& name, int gradeToSign, int gradeToExecute);

		//Use const reference for string to avoid copy, const for method to promise no modification.
		const std::string& getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& b);

		//To make this class abstract
		virtual void execute(Bureaucrat const& executor) const = 0;

		//Inherit from std::exception and override what().
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
		
		class FormNotSignedException : public std::exception
		{
			public: 
				const char* what() const noexcept override;
		};
		
		//Helper for derived execute functions
		protected:
			void checkExecution(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
