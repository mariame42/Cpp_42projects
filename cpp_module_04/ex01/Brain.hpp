#ifndef Brain_H
# define Brain_H

#include "iostream"

class Brain
{
    private :
        std::string _ideas[100];
    public :
        Brain();
        Brain(std::string type);
        ~Brain();
        std::string getIdea(int index) const;
};


#endif