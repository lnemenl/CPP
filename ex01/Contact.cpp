/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:43:08 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/06 08:52:46 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

void Contact::setContact()
{
	std::string input;
	
	std::cout << "[ENTER FIRST NAME]" << std::endl;
	std::getline(std::cin, input);
	if (input.empty()) return;
	firstName = input;

	std::cout << "[ENTER LAST NAME]" << std::endl;
	std::getline(std::cin, input);
	if (input.empty()) return;
	lastName = input;

	std::cout << "[ENTER NICKNAME]" << std::endl;
	std::getline(std::cin, input);
	if (input.empty()) return;
	nickname = input;
	
	std::cout << "[ENTER PHONE NUMBER]" << std::endl;
	std::getline(std::cin, input);
	if (input.empty()) return;
	phoneNumber = input;

	std::cout << "[ENTER DARKEST SECRET]" << std::endl;
	std::getline(std::cin, input);
	if (input.empty()) return;
	darkestSecret = input;
}

void Contact::displaySummary(int index) const
{
	std::cout	<< std::setw(10) << index << "|"
				<< formatField(firstName) << "|"
				<< formatField(lastName) << "|"
				<< formatField(nickname) << "|"
				<< formatField(phoneNumber) << "|"
				<< formatField(darkestSecret) << std::endl;
}

void Contact::displayFull() const
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName <<std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

bool Contact::isEmpty() const
{
	return	firstName.empty() ||
			lastName.empty() ||
			nickname.empty() ||
			phoneNumber.empty() ||
			darkestSecret.empty();
}

