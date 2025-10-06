#ifndef MateriaSource_hpp
#define MateriaSource_hpp

#include "../abstract/AMateria.hpp"
#include "../Interface/IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _Source_slot[4];
        static const int _maxSlots = 4;

    public:
        MateriaSource(/* args */);
        ~MateriaSource();
        void learnMateria(AMateria *matria);
        AMateria* createMateria(std::string const & type);
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
};


#endif