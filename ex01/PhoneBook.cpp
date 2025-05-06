/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:30:13 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/06 14:46:00 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact()
{
	Contact newContact;
	newContact.setContact();

	if (!newContact.isEmpty())
	{
		contacts[nextIndex] = newContact;
		nextIndex = (nextIndex + 1) % MAX_CONTACTS;
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
				<< std::setw(10) << "Nickname" << "|"
				<< std::setw(10) << "Phone" << "|"
				<< std::setw(10) << "Secret" << "\n";
	
	for (int i = 0; i < contactCount; ++i)
		contacts[i].displaySummary(i);
	
	std::cout << "Enter index to view full contact: " << std::endl;

	int index;
	
	if (!(std::cin >> index))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}
	if (index < 0 || index >= contactCount)
		std::cout << "Invalid index\n";
	else
	{
		std::cin.ignore();
		contacts[index].displayFull();
	}
}