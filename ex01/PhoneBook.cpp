/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:30:13 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/06 09:52:24 by rkhakimu         ###   ########.fr       */
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
		std::cout << "Contact added" << std::endl;
	}
	else
	{
		std::cout << "Please fill in all the fields. Contact not saved" << std::endl;
	}
}

void PhoneBook::searchContact() const
{
	if (contactCount == 0)
	{
		std::cout << "A PhoneBook is empty" << std::endl;
		return;
	}
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	
	for (int i = 0; i < contactCount; ++i)
		contacts[i].displaySummary(i);
	
	std::cout << "Enter index to view full contact: " << std::endl;

	int index;
	
	if (!(std::cin >> index))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input" << std::endl;
		return;
	}
	if (index < 0 || index >= contactCount)
	{
		std::cout << "Invalid index" << std::endl;
	}
	else
	{
		std::cin.ignore();
		contacts[index].displayFull();
	}
}