/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:54:13 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/19 15:09:33 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("unnamed"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	//std::cout << "[Form] contructor called" << std::endl;
}

Form::Form(const Form& obj) : _name(obj._name), _signed(obj._signed), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
	//std::cout << "[Form] copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& obj)
{
	if (this != &obj)
	{
		_isSigned = obj._isSigned; //the rest are const
	}
	return *this;
}

Form::~Form()
{
	//std::cout << "[Form] destructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(0)
{
	if (gradeToSign < 1 || gradeToExecute < 1) throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150) throw GradeTooLowException();
}



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