#include "phonebook.hpp"

int main(void)
{
    PhoneBook phoneBook;
    std::string command;
    
    std::cout << GREEN << "Welcome to the PhoneBook!" << RESET << std::endl;
    std::cout << BLUE << "Available commands: " << RESET << "ADD, SEARCH, EXIT" << std::endl;
    while (1)
    {
        std::cout << "\nEnter command: ";
        std::getline(std::cin, command);
        if (command == "ADD")
        {
            add_function(phoneBook);
        }
        else if (command == "SEARCH")
        {
            search_function(phoneBook);
        }
        else if (command == "EXIT")
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else
            std::cout << "Invalid command. Use ADD, SEARCH, or EXIT." << std::endl;
    }
    return 0;
}