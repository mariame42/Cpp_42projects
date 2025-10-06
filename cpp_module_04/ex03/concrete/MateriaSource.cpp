#include "MateriaSource.hpp"
#include "../main.hpp"

MateriaSource::MateriaSource(/* args */)
{
    std::cout << "MateriaSource default constructor" << std::endl; 
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource default destructor" << std::endl;
}


MateriaSource::MateriaSource(const MateriaSource& other) 
{
    for (int i = 0; i < _maxSlots; i++)
    {
        if (other._Source_slot[i])
            _Source_slot[i] = other._Source_slot[i]->clone();
        else
            _Source_slot[i] = NULL;
    }
    std::cout << "MateriaSource copy constructor" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        // Clean up existing backpack_slot
        for (int i = 0; i < _maxSlots; i++)
        {
            if (_Source_slot[i])
            {
                delete _Source_slot[i];
                _Source_slot[i] = NULL;
            }
        }
        // Copy backpack_slot
        for (int i = 0; i < _maxSlots; i++)
        {
            if (other._Source_slot[i])
                _Source_slot[i] = other._Source_slot[i]->clone();
            else
                _Source_slot[i] = NULL;
        }
    }
    std::cout << "MateriaSource copy assignment operator called" << std::endl;
    return (*this);
}

void MateriaSource::learnMateria(AMateria *matria)
{
    if (!matria)
        return;
    
    for (int i = 0; i < _maxSlots; i++)
    {
        if (!_Source_slot[i])
        {
            _Source_slot[i] = matria;
            std::cout << "done in slot " << i << std::endl;
            return;
        }
    }
    std::cout << " cannot save it is full!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < _maxSlots; i++)
    {
        if (_Source_slot[i] && _Source_slot[i]->getType() == type)
        {
            return _Source_slot[i]->clone();
        }
    }
    return 0;
}