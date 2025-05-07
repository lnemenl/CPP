/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:43:00 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/07 07:37:57 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


std::string toUpper(const std::string &str)
{
	std::string result = str;
	for (size_t i = 0; i < result.length(); ++i)
	{
		if (result[i] >= 'a' && result[i] <= 'z')
			result[i] = result[i] - 'a' + 'A';
	}
	return (result);
}

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter ADD | SEARCH | EXIT" << std::endl;
		std::getline(std::cin, command);

		if (std::cin.eof())
		{
			std::cout << "EOF reached\n";
			break;
		}

		std::string cmd_upper = toUpper(command);
			
		if (cmd_upper == "ADD")
			phoneBook.addContact();
		else if (cmd_upper == "SEARCH")
			phoneBook.searchContact();
		else if (cmd_upper == "EXIT")
			break;
		else
			std::cout << "Invalid command" << "\n";
	}
	std::cout << "Bye bye 👋" << "\n";
	return (0);
}