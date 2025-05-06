/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:43:00 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/06 14:33:30 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

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
            
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command" << "\n";
    }
    std::cout << "Bye bye 👋" << "\n";
    return (0);
}