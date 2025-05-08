/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:30:13 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/08 08:45:43 by rkhakimu         ###   ########.fr       */
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
				<< std::setw(10) << "Nickname" << "|"
				<< std::setw(10) << "Phone" << "|"
				<< std::setw(10) << "Secret" << "\n";
	
	for (int i = 0; i < contactCount; ++i)
		contacts[i].displaySummary(i);
	
	std::cout << "Enter index to view full contact: " << std::endl;

	int index;
	/*	If fails, returns false and stream enters a failed state by setting the failbit flag	*/
	if (!(std::cin >> index))
	{
		/*	Clearing the error flag in order stream can be used again	*/
		std::cin.clear();
		/*	Since the invalid input remains in the input buffer,
			we need to discard all characters in the input buffer	*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}
	if (index < 0 || index >= contactCount)
	{
		std::cin.ignore();
		std::cout << "Invalid index\n";
	}
	else
	{
		std::cin.ignore();
		contacts[index].displayFull();
	}
}