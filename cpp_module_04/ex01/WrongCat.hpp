#ifndef WrongCat_h
# define WrongCat_h

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public :
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& other);
        const std::string getType() const;
        void makeSound() const;
};

#endif