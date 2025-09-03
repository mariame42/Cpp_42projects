#ifndef Sample_hpp
# define Sample_hpp

#include <iostream>

class Sample {
    private:
    int _value;
    
    public:
    // 1. Default constructor
    Sample() : _value(0) {
        std::cout << "Default constructor called" << std::endl;
    }
    
    // 2. Copy constructor
    Sample(const Sample& other) : _value(other._value) {
        std::cout << "Copy constructor called" << std::endl;
    }
    
    // 3. Copy assignment operator
    Sample& operator=(const Sample& other) {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) {   // protect against self-assignment
            this->_value = other._value;
        }
        return *this;
    }
    
    // 4. Destructor
    ~Sample() {
        std::cout << "Destructor called" << std::endl;
    }

    int value_value(int _value)
    {
        return (_value);
    }
};

#endif