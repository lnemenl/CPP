/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:29:11 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/25 11:00:32 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unnamed"), _grade(150)
{
    // _name is const, so it must be initialized in the initializer list
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    if (grade < 1) throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
    _grade = grade;
}

const std::string& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    ++_grade;
}


//Passing Form by reference to allow modification and avoid copy
void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this); // Pass this Bureaucrat object to the form (as a reference)
        // *this dereferences the pointer to the current object, giving a reference
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << _name << " could not sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
