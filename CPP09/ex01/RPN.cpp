#include "RPN.hpp"

RPN::RPN()
{};

RPN::~RPN()
{};

void RPN::applyOperator(const std::string &op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error size is 2 or bigger");
    
    int stack_b = _stack.top(); _stack.pop();
    int stack_a = _stack.top(); _stack.pop();

    if (op == "+")
        _stack.push(stack_a + stack_b);
    else if (op == "*")
        _stack.push(stack_a * stack_b);
    else if (op == "-")
        _stack.push(stack_a - stack_b);
    else if (op == "/")
    {
        if (stack_b == 0)
            throw std::runtime_error("Error cant divide 0 by 0");
        else
            _stack.push(stack_a / stack_b);
    }
    else
        throw std::runtime_error("Error Operator not found " + op);
}

int RPN::calculate(const std::string &expressions)
{
    // No clear() for std::stack, so reassign a new stack
    _stack = std::stack<int>();
    std::stringstream iss(expressions);
    std::string token;

    while  (iss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
            _stack.push(token[0] - '0');
        else if (token == "+" || token == "-" || token == "*" || token == "/")
            applyOperator(token);
        else
            throw std::runtime_error("Error number or operations not found " + token);
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Stack must have size of 1");
    return _stack.top();
}