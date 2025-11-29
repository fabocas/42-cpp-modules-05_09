#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>

class Array
{
    public:
        Array();
        Array(unsigned int n);
       ~Array();
       unsigned int size() const;
       Array& operator=(const Array& other); //copy assignment Operator 
       Array(const Array &other);
       T& operator[](unsigned int index);
       const T& operator[](unsigned int index) const;

    private:
        T* _data; // ponteiro para o primeiro elemento do array
        unsigned int _size;
};

#include "Array.tpp"
