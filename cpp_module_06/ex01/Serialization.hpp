#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <iostream>
#include <stdint.h>

struct Data { int id; std::string name; };

class Serialization
{
    private:
        Serialization(/* args */);
        ~Serialization();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif