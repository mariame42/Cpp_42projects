#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n) {
            _array = new T[n];
            _size = n;
        }
        Array(const Array &other) {
            _size = other._size;
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i];
        }
        T &operator[](unsigned int index) {
            if (index >= _size)
                throw std::out_of_range("Index out of bounds");
            return _array[index];
        }
        const T &operator[](unsigned int index) const {
            if (index >= _size)
                throw std::out_of_range("Index out of bounds");
            return _array[index];
        }
        ~Array() {
            delete[] _array;
        }

        unsigned int size() const {
            return _size;
        }

};

#endif