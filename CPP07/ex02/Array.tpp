#pragma once
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
    std::cout << "Constructor Called" << std::endl;
}
template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n)
{
}
template <typename T>
unsigned int Array<T>::size() const
{
    return this->_size;
}
template <typename T>
Array<T>::~Array()
{
    delete[] _data;
    _data = NULL;
}
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] this->_data;
        this->_size = other._size;
        this->_data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
    return *this;
}
template <typename T>
Array<T>::Array(const Array &other)
{
    this->_size = other._size;
    if (_size > 0)
    {
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= this->_size)
        throw std::out_of_range("Index out of bounds");
    return _data[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= this->_size)
        throw std::out_of_range("Index out of bounds");
    return this->_data[index];
}