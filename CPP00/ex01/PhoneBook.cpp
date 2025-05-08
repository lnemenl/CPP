/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:30:13 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/08 13:30:26 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): contactCount(0), nextIndex(0) {}

void PhoneBook::addContact()
{
	Contact newContact;
	newContact.setContact();

	if (!newContact.isEmpty())
	{
		contacts[nextIndex % MAX_CONTACTS] = newContact;
		nextIndex++;
		if (contactCount < MAX_CONTACTS)
			++contactCount;
		std::cout << "Contact added\n";
	}
	else
		std::cout << "Please fill in all the fields. Contact not saved\n";
}

void PhoneBook::searchContact() const
{
	if (contactCount == 0)
	{
		std::cout << "A PhoneBook is empty\n";
		return;
	}
	std::cout	<< std::setw(10) << "Index"	<< "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "\n";
	
	for (int i = 0; i < contactCount; ++i)
		contacts[i].displaySummary(i);
	
	std::cout << "Enter index to view full contact: " << std::endl;
	std::string input;
    std::getline(std::cin, input);
    if (std::cin.eof())
	{
        std::cin.clear();
        return;
    }
    if (input.empty())
	{
        std::cout << "Invalid input: empty string\n";
        return;
    }
    for (size_t i = 0; i < input.length(); ++i)
	{
        if (!std::isdigit(input[i]))
		{
            std::cout << "Invalid input: not a number\n";
            return;
        }
    }
    int index = std::stoi(input);
    if (index < 0 || index >= contactCount)
        std::cout << "Invalid index\n";
	else
        contacts[index].displayFull();
}