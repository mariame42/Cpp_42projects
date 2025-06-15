#include <iostream> 
#include <string>

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
    if (phoneBook->pos == 8)
    {
        phoneBook->pos = 0;
        phoneBook->count = 0;
    }
    std::cout << "add\n";
    std::cout << "add your first name mesio ";
    std::cin >> phoneBook->contact[phoneBook->pos].first_name;
    std::cout<<"add your last name mesio ";
    std::cin>>phoneBook->contact[phoneBook->pos].last_name;
    std::cout<<"add your nick name mesio ";
    std::cin>>phoneBook->contact[phoneBook->pos].nickname;
    std::cout<<"add your number mesio ";
    std::cin>>phoneBook->contact[phoneBook->pos].phone_number;
    std::cout<<"add your darkest_secret mesio ";
    std::cin>>phoneBook->contact[phoneBook->pos].darkest_secret;
    phoneBook->pos++;
    phoneBook->count = phoneBook->pos;
}
void  search_function(PhoneBook *phoneBook)
{
    int i = 0;
    std::cout<<"search\n";
    std::cout<<"|----------|----------|----------|----------|"<< std::endl;
    std::cout<<"|--index---|first name|last  name|nick  name|"<< std::endl;
    while (!phoneBook->contact[i].first_name.empty() && i < 8)
    {
        std::cout<<"|----------|----------|----------|----------|"<< std::endl;
        std::cout<<"|" << "    " << i << "     " << "|" << phoneBook->contact[i].first_name << "|" << phoneBook->contact[i].last_name << "|" << phoneBook->contact[i].nickname << "|" << std::endl;
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