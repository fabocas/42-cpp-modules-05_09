#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <iomanip>
#include <limits>




class ScalarConverter
{
    public:
        static void convert(const std::string &literal);
        

    private:
        template <typename T>
        static bool fromString(const std::string &s, T &value);

};

#include "ScalarConverter.tpp"