/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:48:16 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/25 21:58:08 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


const char* Intern::FormNotFoundException::what() const noexcept
{
	return "Form not found";
}

static AForm* createShrubbery(const std::string& t)
{
	return new ShrubberyCreationForm(t);
}

static AForm* createRobotomy(const std::string& t)
{
	return new RobotomyRequestForm(t);
}

static AForm* createPardon(const std::string& t)
{
	return new PresidentialPardonForm(t);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	// Using arrays to map form names to their creation functions.
	const std::string names[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	// This is an array of function pointers (array of pointers to functions)
	// Each pointer points to a function that takes a const std::string& (the target)
	// and returns a pointer to AForm.
	AForm* (*creators[])(const std::string&) =
	{
		createShrubbery,
		createRobotomy,
		createPardon
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return creators[i](target);
		}
	}
	
	throw FormNotFoundException();
}
