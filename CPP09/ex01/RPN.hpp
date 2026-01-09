#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

class RPN
{
    public:
        RPN();
        ~RPN();
        int calculate(const std::string &expressions);

    private:
        std::stack<int> _stack;
        void applyOperator(const std::string &op);

};