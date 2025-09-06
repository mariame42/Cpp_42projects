#ifndef ClapTrap_CPP
#define ClapTrap_CPP

#include <iostream>

// a flag to show when Orthodox Canonical class form is used
// turn it on when we want to see the constructor and destructor messages
#define OCCF 1

class ClapTrap {
    private:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;

    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif