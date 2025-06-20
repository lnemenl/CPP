/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:54:13 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/20 11:54:12 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("unnamed"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    //Setting values to 1 and only grade 1 bureaucrats can sign/execute (valid, but restrictive).
    // 150 is the most permissive (lowest grade), so any bureaucrat can sign/execute.
}

Form& Form::operator=(const Form& obj)
{
    if (this != &obj)
        _isSigned = obj._isSigned;
    return *this;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1) throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150) throw GradeTooLowException();
}

//Getter for name: returns a const reference to the name (no copy, not modifiable)
const std::string& Form::getName() const
{
    return _name;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

bool Form::isSigned() const
{
    return _isSigned;
}

// C++ Rule: Pass by const reference for efficiency and safety (no copy, not modified)
void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _gradeToSign) throw GradeTooLowException();
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const noexcept
{
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const noexcept
{
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form '" << f.getName() << "', signed: " << (f.isSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}
