#include "phonebook.hpp"

void displayc_ten_char(const std::string& str)
{
    if (str.length() <= 10) {
        std::cout << std::setw(10) << str;
    } else {
        for (size_t i = 0; i < 9; i++) {
            std::cout << str[i];
        }
        std::cout << ".";
    }
}

bool containsOnlySpaces(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] != ' ') {
            return false;
        }
    }
    return true;
}

int extra_checks(std::string first_name, std::string last_name, std::string phone_number, PhoneBook& phoneBook)
{
    for (size_t i = 0; i < first_name.length(); ++i) {
        if (std::isdigit(first_name[i])) {
            std::cout << "Error: First name cannot contain numbers!" << std::endl;
            return 1;
        }
    }
    for (size_t i = 0; i < last_name.length(); ++i) {
        if (std::isdigit(last_name[i])) {
            std::cout << "Error: Last name cannot contain numbers!" << std::endl;
            return 1;
        }
    }
    // Check phone number: only digits, or a single + at the start
    size_t start = 0;
    if (phone_number[0] == '+') {
        start = 1;
        if (phone_number.length() == 1) {
            std::cout << "Error: Phone number must contain digits after +!" << std::endl;
            return 1;
        }
    }
    for (size_t i = start; i < phone_number.length(); ++i) {
        if (!std::isdigit(phone_number[i])) {
            std::cout << "Error: Phone number can only contain digits (and an optional + at the start)!" << std::endl;
            return 1;
        }
    }
// After the phone number validation
    if (phone_number.length() < 7 || phone_number.length() > 15) {
        std::cout << "Error: Phone number must be between 7 and 15 digits!" << std::endl;
        return 1;
    }
    if (first_name.length() > 50 || last_name.length() > 50) {
        std::cout << "Error: Names cannot exceed 50 characters!" << std::endl;
        return 1;
    }
// Check if phone number already exists in phonebook
    for (int i = 0; i < phoneBook.getCount(); ++i) {
        if (phoneBook.getContact(i).getPhoneNumber() == phone_number) {
            std::cout << "Error: Phone number already exists!" << std::endl;
            return 1;
        }
    }
    return 0;
}