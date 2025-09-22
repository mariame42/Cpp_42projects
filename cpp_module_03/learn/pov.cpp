#include <iostream>


int main()
{
    std::string pov = "_clap_name";
    std::string name = "Default";
    name = name + pov;
    std::cout << name << std::endl;
    return 0;
}

std::string cjoint(std::string name, std::string pov)
{
    return (name + pov);
}