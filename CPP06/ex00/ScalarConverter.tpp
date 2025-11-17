#include "ScalarConverter.hpp"

template <typename T>

bool ScalarConverter::fromString(const std::string &s, T &value)
{
    std::stringstream ss(s);
    ss >> value;
    return !ss.fail() && ss.eof();
}