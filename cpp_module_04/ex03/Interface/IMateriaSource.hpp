#ifndef IMateriaSource_hpp
# define IMateriaSource_hpp

#include "iostream"
#include "../abstract/AMateria.hpp"
#include "../derived/Character.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif