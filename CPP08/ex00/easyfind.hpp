#pragma once
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iostream>


template <typename T>
// function that takes type T and second one is an integer it needs to find the first occurrence of the second parameter in the first parameter.
typename T::iterator easyfind(T &first, int second)
{
    typename T::iterator it = std::find(first.begin(), first.end(), second);
    if (it == first.end())
        throw std::runtime_error("Value Not Found"); 
    return it;
}