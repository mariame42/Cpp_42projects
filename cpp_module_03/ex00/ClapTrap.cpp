#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    if (OCCF)
        std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    if (OCCF)
        std::cout << GREEN << "Parameterized constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    if (OCCF)
        std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap& operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    if (OCCF)
        std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    if (OCCF)
        std::cout << RED << "Destructor called" << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target);
void ClapTrap::takeDamage(unsigned int amount);
void ClapTrap::beRepaired(unsigned int amount);