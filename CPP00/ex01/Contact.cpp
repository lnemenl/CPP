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

bool Contact::checkField(std::string& input)
{
	std::getline(std::cin, input);
	if (std::cin.eof()) return false;
	
	while (input.empty())
	{
		if (std::cin.eof()) return false;
		std::cout << "This field cannot be empty!" << std::endl;
		getline(std::cin, input);
	}
	return true;
}

void Contact::setContact()
{
	std::string input;
	
	std::cout << "ENTER FIRST NAME" << std::endl;
	if (!checkField(input))
		return ;
	firstName = input;

	std::cout << "ENTER LAST NAME" << std::endl;
	if (!checkField(input))
		return ;
	lastName = input;

	std::cout << "ENTER NICKNAME" << std::endl;
	if (!checkField(input))
		return ;
	nickname = input;

	std::cout << "ENTER PHONE NUMBER" << std::endl;
	while (true)
	{
		if (!checkField(input))
		return ;
		if (isNumeric(input))
		{
			phoneNumber = input;
			break;
		}
		std::cout << "Phone number must contain only digits" << std::endl;
	}
	std::cout << "ENTER DARKEST SECRET" << std::endl;
	if (!checkField(input))
		return ;
	darkestSecret = input;
}

void Contact::displaySummary(int index) const
{
	std::cout	<< std::setw(10) << index << "|"
				<< formatField(firstName) << "|"
				<< formatField(lastName) << "|"
				<< formatField(nickname) << std::endl;
}

void Contact::displayFull() const
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
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
