/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:53:59 by meid              #+#    #+#             */
/*   Updated: 2025/07/12 15:55:07 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hpp_files/main.hpp"

void PhoneBook::startYourPhonebookApp(void)
{
    std::string command;
    
    std::cout << GREEN << "Welcome to the PhoneBook!" << RESET << std::endl;
    std::cout << BLUE << "Available commands: " << RESET << Cyan << "ADD, SEARCH, EXIT" << RESET << std::endl;
    while (1)
    {
        std::cout << Cyan << "\nEnter command: ";
        if (!std::getline(std::cin, command)) {
            std::cout << RESET;
            std::cout << RED <<"\nEOF detected. Exiting..." << RESET << std::endl;
            break; // or exit(0), or return, depending on your structure
        }
        std::cout << RESET;
        if (command == "ADD")
        {
            add_function();
        }
        else if (command == "SEARCH")
        {
            search_function();
        }
        else if (command == "EXIT")
        {
            std::cout << GREEN << "Goodbye!" << RESET << std::endl;
            break;
        }
        else
            std::cout << RED << "Invalid command. Use ADD, SEARCH, or EXIT." << RESET << std::endl;
    }
}

void PhoneBook::addContact(const Contact& newContact) {
    _contact[_pos] = newContact;
    _pos = (_pos + 1) % 8;
    if (_count < 8) _count++;
}

int PhoneBook::check_phonenumber(const std::string& phone_number)
{
    size_t start = 0;
    int plus = 0;
    if (phone_number[0] == '+') {
        start = 1;
        plus = 1;
        if (phone_number.length() == 1) {
            std::cout << RED << "Error: Phone number must contain digits after +!" << RESET << std::endl;
            return 1;
        }
    }

    for (size_t i = start; i < phone_number.length(); i++) {
        if (!std::isdigit(phone_number[i])) {
            std::cout << RED << "Error: Phone number can only contain digits (and an optional + at the start)!" << RESET << std::endl;
            return 1;
        }
    }
    // https://en.wikipedia.org/wiki/E.164
    if ((plus &&( phone_number.length() < 4 || phone_number.length() > 16)) || (!plus &&( phone_number.length() < 3 || phone_number.length() > 15))) {
        std::cout << RED << "Error: Phone number must be between 3 and 15 digits!" << RESET << std::endl;
        return 1;
    }

    for (int i = 0; i < getCount(); i++) {
        if (_contact[i].getPhoneNumber() == phone_number) {
            std::cout << RED << "Error: Phone number already exists!" << RESET << std::endl;
            return 1;
        }
    }
    return (0);
}


void PhoneBook::add_function()
{
    std::string first_name = check_for_eof_and_print("Enter first name: ", Bright_Magenta);
    if (first_name.empty() || name_check(first_name)) return; // or handle EOF
    
    std::string last_name = check_for_eof_and_print("Enter last name: ", Bright_Magenta);
    if (last_name.empty() || name_check(last_name)) return;
    
    std::string nickname = check_for_eof_and_print("Enter nickname: ", Bright_Magenta);
    if (nickname.empty()) return;
    
    std::string phone_number = check_for_eof_and_print("Enter phone number: ", Bright_Magenta);
    if (phone_number.empty() || check_phonenumber(phone_number)) return;
    
    std::string darkest_secret = check_for_eof_and_print("Enter darkest secret: ", Bright_Magenta);
    if (darkest_secret.empty()) return;
    
    Contact newContact;
    newContact.setFirstName(first_name);
    newContact.setLastName(last_name);
    newContact.setNickname(nickname);
    newContact.setPhoneNumber(phone_number);
    newContact.setDarkestSecret(darkest_secret);
    
    PhoneBook::addContact(newContact);
    std::cout << GREEN << "Contact added successfully!" << RESET << std::endl;
}

void  PhoneBook::search_function()
{
    if (getCount() == 0) {
        std::cout << Bright_Yellow << "Phonebook is empty!" << RESET << std::endl;
        return;
    }
    
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    std::cout << "|     Index|First Name| Last Name| Nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    
    for (int i = 0; i < getCount(); i++) {
        std::cout << "|";
        std::cout << std::setw(10) << i << "|";
        displayc_ten_char(getContact(i).getFirstName());
        std::cout << "|";
        displayc_ten_char(getContact(i).getLastName());
        std::cout << "|";
        displayc_ten_char(getContact(i).getNickname());
        std::cout << "|" << std::endl;
    }
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    std::string input;
    std::cout << "Enter contact index: ";
    
    if (!std::getline(std::cin, input)) {
        std::cout << "\nEOF detected. Exiting..." << std::endl;
        return;
    }
    
    // Check if the input contains only digits
    bool isValid = !input.empty();
    for (size_t i = 0; i < input.length(); ++i) {
        if (!isdigit(input[i])) {
            isValid = false;
            break;
        }
    }
    
    if (!isValid) {
        std::cout << RED << "Invalid input. Please enter a number only." << RESET << std::endl;
        return;
    }
    
    // Safe to convert now
    std::istringstream iss(input);
    int index;
    iss >> index;
    
    if (index >= 0 && index < PhoneBook::getCount()) {
        Contact contact = PhoneBook::getContact(index);
        std::cout << "First Name: " << contact.getFirstName() << std::endl;
        std::cout << "Last Name: " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickname() << std::endl;
        std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
    } else {
        std::cout << RED << "Invalid index!" << RESET << std::endl;
    }
    
}


PhoneBook::PhoneBook() : _pos(0), _count(0) {};
int PhoneBook::getCount() const { return _count; }
int PhoneBook::get_pos() const { return _pos; }
Contact PhoneBook::getContact(int index) const { return _contact[index]; }