#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Lion")
{
    std::cout << "Lion constructor called" << std::endl;
}


WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout  << "WrongCat Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);
    }
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    return (*this);
}

void WrongCat::makeSound()  const
{
    std::cout << "growl" << std::endl;
}

const std::string WrongCat::getType() const
{
    return (_type);
}