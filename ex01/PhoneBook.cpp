/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:30:13 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/05 17:07:44 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
	
	
}