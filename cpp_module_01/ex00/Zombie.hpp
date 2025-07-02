#ifndef Zombie_h
#define Zombie_h

#include <string>
#include <iostream>

class Zombie {
    private:
        std::string name;

    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
        void setName(std::string name);

};

#endif