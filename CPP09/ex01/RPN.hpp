#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

class RPN
{
    public:
        RPN();
        ~RPN();
        int calculate(const std::string &expressions);

    private:
        std::vector<int> _stack;
        void applyOperator(const std::string &op);

};