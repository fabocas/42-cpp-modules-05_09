#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N)
{

};

void Span::addNumber(unsigned int num)
{
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("value exceeds maxsize");
    if (std::find(_numbers.begin(), _numbers.end(), num) != _numbers.end())
        throw std::runtime_error("value already exists");
    _numbers.push_back(num);
}


int Span::shortestSpan()
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("there is only one number or it is empty");
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());;
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < tmp.size(); i++)
    {
        int span = tmp[i] - tmp[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("there is only one number or it is empty");
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    return tmp.back() - tmp.front();
}
int Span::operator[](unsigned int index) const
{
    if (index >= _numbers.size())
        throw std::runtime_error("Index out of range");
    return _numbers[index];
}

unsigned int Span::size() const
{
    return this->_numbers.size();
}
Span::~Span()
{

};