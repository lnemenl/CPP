#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& obj) = default;
        Bureaucrat& operator=(const Bureaucrat& obj) = delete;
        ~Bureaucrat() = default;
        // Parameterized constructor
        explicit Bureaucrat(const std::string& name, int grade);

        // const reference for string to avoid copy, const for method to promise no modification.
        const std::string& getName() const;
        int getGrade() const; //The const at the end means this function does NOT modify any member variables of the object AND I can call this function on const objects.

        // These methods change the grade, so not const.
        void incrementGrade();
        void decrementGrade();

        void signForm(AForm& form) const; // Pass by reference to modify the Form

        // Exceptions
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

        void executeForm(AForm const& form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif


/*
Bureaucrat::signForm(AForm& form) const
 └─ I promise: I won’t change *me* (Bureaucrat)
 └─ I might change *form* (e.g. sign it)

Bureaucrat::executeForm(const AForm& form) const
 └─ I promise: I won’t change *me*
 └─ I won’t change *form* (just tell it to execute itself)
*/