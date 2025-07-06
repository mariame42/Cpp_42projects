#include "phonebook.hpp"

void add_function(PhoneBook& phoneBook)
{
    std::string first_name, last_name, nickname, phone_number, darkest_secret;
    
    std::cout << "Enter first name: ";
    std::getline(std::cin, first_name);
    
    std::cout << "Enter last name: ";
    std::getline(std::cin, last_name);
    
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone_number);
    
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkest_secret);
    
    // Check if any field is empty
    if (first_name.empty() || last_name.empty() || nickname.empty() || 
        phone_number.empty() || darkest_secret.empty() ||
        containsOnlySpaces(first_name) || containsOnlySpaces(last_name) ||
        containsOnlySpaces(nickname) || containsOnlySpaces(phone_number) ||
        containsOnlySpaces(darkest_secret)) {
        std::cout << "Error: All fields must be filled and cannot be only spaces!" << std::endl;
        return;
    }
    else if (extra_checks(first_name, last_name, phone_number, phoneBook))
        return;
    
    Contact newContact;
    newContact.setFirstName(first_name);
    newContact.setLastName(last_name);
    newContact.setNickname(nickname);
    newContact.setPhoneNumber(phone_number);
    newContact.setDarkestSecret(darkest_secret);
    
    phoneBook.addContact(newContact);
    std::cout << "Contact added successfully!" << std::endl;
}

void  search_function(PhoneBook& phoneBook)
{
    if (phoneBook.getCount() == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }
    
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    std::cout << "|     Index|First Name| Last Name| Nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    
    for (int i = 0; i < phoneBook.getCount(); i++) {
        std::cout << "|";
        std::cout << std::setw(10) << i << "|";
        displayc_ten_char(phoneBook.getContact(i).getFirstName());
        std::cout << "|";
        displayc_ten_char(phoneBook.getContact(i).getLastName());
        std::cout << "|";
        displayc_ten_char(phoneBook.getContact(i).getNickname());
        std::cout << "|" << std::endl;
    }
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    
    // Prompt for index input
    std::cout << "Enter index to display contact details: ";
    std::string input;
    std::getline(std::cin, input);
    
    // std::stoi
    int index = atoi(input.c_str());
    if (index >= 0 && index < phoneBook.getCount()) {
        Contact contact = phoneBook.getContact(index);
        std::cout << "First Name: " << contact.getFirstName() << std::endl;
        std::cout << "Last Name: " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickname() << std::endl;
        std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
    } else {
        std::cout << "Invalid index!" << std::endl;
    }
}
