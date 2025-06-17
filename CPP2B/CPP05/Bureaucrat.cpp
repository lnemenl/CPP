/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:29:11 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/17 11:00:39 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat () : _name(), _grade()
{
	//std::cout << "[Bureaucrat] Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade)
{
	//std::cout << "[Bureaucrat] Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
		_grade = obj._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << "[Bureaucrat] desctructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
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
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& grade_)
{
	os << grade_.getName() << " , bureaucrat grade " << grade_.getGrade();
}
