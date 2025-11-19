#pragma once
#include <iostream>


template <typename T, typename F>

void iter(T* arr, const _sizet len, F func)
{
    if (!arr || !func)
        return ;
    for (_sizet i = 0; i < len; i++)
        func(arr[i]);
}







