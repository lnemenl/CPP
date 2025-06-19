/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:54:13 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/19 11:37:48 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(), _signed(0), _gradeToSign(), _gradeToExecute()
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
		_signed = obj._signed;
	}
	return *this;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(0)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
	//std::cout << "[Form] destructor called" << std::endl;
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

bool Form::signed() const
{
	return _signed;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() >= _gradeToSign)
		throw GradeTooLowException();
	_signed = 1;
}

