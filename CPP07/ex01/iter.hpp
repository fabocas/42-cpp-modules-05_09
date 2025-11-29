#pragma once
#include <iostream>


template <typename T, typename F>

void iter(T* arr, const size_t len, F func)
{
    if (!arr || !func)
        return ;
    for (_sizet i = 0; i < len; i++)
        func(arr[i]);
}







