/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:43:08 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/08 11:09:21 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

bool Contact::isNumeric(const std::string &str) const
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

void Contact::setContact()
{
	std::string input;
	

	std::cout << "ENTER FIRST NAME" << std::endl;
	std::getline(std::cin, input);
	if (input.empty()) return;
	firstName = input;

	std::cout << "ENTER LAST NAME" << std::endl;
	std::getline(std::cin, input);
	if (input.empty()) return;
	lastName = input;

	std::cout << "ENTER NICKNAME" << std::endl;
	std::getline(std::cin, input);
	if (input.empty()) return;
	nickname = input;

	std::cout << "ENTER PHONE NUMBER" << std::endl;
	while (true)
	{
		std::getline(std::cin, input);
		if (input.empty()) return;
		if (isNumeric(input))
		{
			phoneNumber = input;
			break;
		}
		std::cout << "Phone number must contain only digits" << std::endl;
	}

	std::cout << "ENTER DARKEST SECRET" << std::endl;
	std::getline(std::cin, input);
	if (input.empty()) return;
	darkestSecret = input;
}

void Contact::displaySummary(int index) const
{
	std::cout	<< std::setw(10) << index << "|"
				<< formatField(firstName) << "|"
				<< formatField(lastName) << "|"
				<< formatField(nickname) << "\n";
}

void Contact::displayFull() const
{
	std::cout << "First name: " << firstName << "\n";
	std::cout << "Last name: " << lastName << "\n";
	std::cout << "Nickname: " << nickname << "\n";
	std::cout << "Phone number: " << phoneNumber << "\n";
}

bool Contact::isEmpty() const
{
	return	firstName.empty() ||
			lastName.empty() ||
			nickname.empty() ||
			phoneNumber.empty() ||
			darkestSecret.empty();
}

std::string Contact::formatField(const std::string &field) const
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	else
		return (std::string(10 - field.length(), ' ') + field);
}
