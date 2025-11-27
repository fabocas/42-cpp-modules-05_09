#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <iostream>

class Span
{
    public:
        void addNumber(unsigned int num);
        ~Span();
        int shortestSpan();
        int longestSpan();
        Span(unsigned int N);
        unsigned int size() const;
        int operator[](unsigned int index) const;

    private:
        std::vector<int> _numbers;
        unsigned int _maxSize;

};