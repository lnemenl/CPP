#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;
    do
	{
        std::cout << "Enter ADD | SEARCH | EXIT" << std::endl;
        if (!std::getline(std::cin, command))
            break;
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command" << std::endl; 
    }
	while (!std::cin.eof());
    std::cout << "Bye bye 👋" << std::endl;
    return (0);
}
