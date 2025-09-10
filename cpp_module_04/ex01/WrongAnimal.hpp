#ifndef WrongAnimal_h
# define WrongAnimal_h

#include "iostream"

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        ~WrongAnimal();
        virtual const std::string getType() const;
        virtual void makeSound() const;
};

#endif