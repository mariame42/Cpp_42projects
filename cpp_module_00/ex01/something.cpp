#include <iostream> 
#include <string>
#include <cstring> // strlen

class Contact
{
    public: 
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    // void setFirstName(std::string fName){
    //     first_name = fName;
    // }
    // void setFirstName(std::string fName){
    //     first_name = fName;
    // }
};
class PhoneBook
{
    public:
        Contact contact[8];
        int pos;
        int count;
};

void add_function(PhoneBook *phoneBook)
{
    
    std::string first_name, last_name, nickname, phone_number, darkest_secret;
    if (phoneBook->pos == 8)
    {
        phoneBook->pos = 0;
        phoneBook->count = 0;
    }
    Contact& current = phoneBook->contact[phoneBook->pos];
    std::cout<<"new contect";
    std::cout << "add\n";
    std::cout << "add your first name Monsieur ";
    std::cin >> first_name;
    std::cout<<"add your last name Monsieur ";
    std::cin >> last_name;
    std::cout<<"add your nick name Monsieur ";
    std::cin >>nickname;
    std::cout<<"add your number Monsieur ";
    std::cin >> phone_number;
    std::cout<<"add your darkest_secret Monsieur ";
    std::cin >> darkest_secret;
    if (
        !(first_name).empty() &&
        !(last_name).empty() &&
        !(nickname).empty() &&
        !(phone_number).empty() &&
        !(darkest_secret).empty()       
    )
    {
        std::cout<<"here";
        current.first_name = first_name;
        current.last_name = last_name;
        current.nickname = nickname;
        current.phone_number = phone_number;
        current.darkest_secret = darkest_secret;
        phoneBook->pos++;
        phoneBook->count = phoneBook->pos;
    }
}

void displayc_ten_char(std::string str)
{
    int i = 0;
    while (i < 10)
    {
        if (str[i])
            std::count<<str[i];
        else
        i++;
    }
}

void  search_function(PhoneBook *phoneBook)
{
    int i = 0;
    std::cout<<"search\n";
    std::cout<<"|----------|----------|----------|----------|"<< std::endl;
    std::cout<<"|--index---|first name|last  name|nick  name|"<< std::endl;
    // phoneBook->contact[i].first_name.empty()
    while (i < phoneBook->count)
    {
        std::cout<<"|----------|----------|----------|----------|"<< std::endl;
        std::cout<<"|" << "    " << i << "     " << "|";
        displayc_ten_char(phoneBook->contact[i].first_name);
        std::cout << "|";
        displayc_ten_char(phoneBook->contact[i].last_name);
        std::cout << "|";
        displayc_ten_char(phoneBook->contact[i].nickname);
        std::cout << "|";
        std::endl;
        i++;
    }
    std::cout<<"|----------|----------|----------|----------|"<< std::endl;
}

int main(void)
{
    PhoneBook phoneBook;
    phoneBook.count = 0;
    phoneBook.pos = 0;
    // phoneBook.contact[0].last_name = "Mariam";
    // std::cout<< phoneBook.contact[0].first_name;
    while (1)
    {
        std::string ko;
        std::cin>>ko;
        if (ko == "ADD")
        {
            add_function(&phoneBook);
        }
        else if (ko == "SEARCH")
        {
            search_function(&phoneBook);
        }
        else if (ko == "EXIT")
        {
            break;
        }
    }
    
    // std::cout<<ko;
}