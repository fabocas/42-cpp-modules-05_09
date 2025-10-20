

#include "ScalarConverter.hpp"



bool ScalarConverter::isInt(const std::string &literal)
{
    if (literal.empty())
        return false;
   size_t i = 0;

    if (literal == "+" || literal == "-")
        i = 1;

    if (i == literal.size())
    {
        std::cout << "wrong input, try adding numbers after + or -" << std::endl;
        return false;
    }
    for(; i < literal.size();i++)
    {
        if (!isdigit(literal[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isChar(const std::string &literal)
{
    if (literal.empty())
        return false;

    if (literal != 1)
        return false;
    char c = literal[0];
    if (std::isprint(c) && !std::isdigit(c))
        return true;
    return false;
}
void ScalarConverter::convert(const std::string &literal)
{
    if (isInt(literal))
    {
        int value = stoi(literal);
        std::cout <<  "int: "  << value << std::endl;
    }
    if (isChar(literl))
    {
        char c = 
    }
    if ((stoi(literal)) == 2147483647 )
    {
        std::cout << "Number Achieved max int" << std::endl;
        return ;
    }

    //Char

    //int

    //float


    //double
}