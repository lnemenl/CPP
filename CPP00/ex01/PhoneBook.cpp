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
		if (nextIndex == MAX_CONTACTS)
			nextIndex = 0;
		if (contactCount < MAX_CONTACTS)
			++contactCount;
		std::cout << "Contact added" << std::endl;
	}
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
				<< std::setw(10) << "Nickname" << std::endl;
	
	for (int i = 0; i < contactCount; ++i)
		contacts[i].displaySummary(i);
	
	std::cout << "Enter index to view full contact: " << std::endl;
	std::string input;
    std::getline(std::cin, input);
    if (std::cin.eof())
	{
        std::cin.clear();
		std::cout << "Bye bye 👋" << std::endl;
		exit(0);
        return;
    }
    if (input.empty())
	{
        std::cout << "Invalid input: empty string" << std::endl;
        return;
    }
    for (size_t i = 0; i < input.length(); ++i)
	{
        if (!std::isdigit(input[i]) && i != 0)
		{
            std::cout << "Invalid input: not a number" << std::endl;
            return;
        }
    }
	try
	{
	    int index = std::stoi(input);
		if (index < 0 || index >= contactCount)
        std::cout << "Invalid index\n";
		else
        	contacts[index].displayFull();
	}
	catch (std::exception &e)
	{
        std::cout << "Invalid index" << std::endl;
	}
}