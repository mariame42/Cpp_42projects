#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream> 
#include <string>
#include <cstring> // strlen
#include <iomanip> // for setw
#include <cstdlib> // for atoi
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Contact
{
    private: 
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    
    public:
        // Setters
        void setFirstName(std::string fName) { first_name = fName; }
        void setLastName(std::string lName) { last_name = lName; }
        void setNickname(std::string nName) { nickname = nName; }
        void setPhoneNumber(std::string pNumber) { phone_number = pNumber; }
        void setDarkestSecret(std::string dSecret) { darkest_secret = dSecret; }
        
        // getters
        std::string getFirstName() { return first_name; }
        std::string getLastName() { return last_name; }
        std::string getNickname() { return nickname; }
        std::string getPhoneNumber() { return phone_number; }
        std::string getDarkestSecret() { return darkest_secret; }
};

class PhoneBook
{
    private:
        Contact contact[8];
        int pos;
        int count;
    
    public:
        PhoneBook() : pos(0), count(0) {}
        
        void addContact(const Contact& newContact) {
            contact[pos] = newContact;
            pos = (pos + 1) % 8;
            if (count < 8) count++;
        }
        
        int getCount() const { return count; }
        Contact getContact(int index) const { return contact[index]; }
};

int extra_checks(std::string first_name, std::string last_name, std::string phone_number, PhoneBook& phoneBook);
void displayc_ten_char(const std::string& str);
bool containsOnlySpaces(const std::string& str);
void add_function(PhoneBook& phoneBook);
void search_function(PhoneBook& phoneBook);


#endif