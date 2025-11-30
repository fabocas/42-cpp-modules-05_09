#include "RPN.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage ./RPN \"'Num and op\"'\"" << std::endl;
        return 1;
    }
    try
    {
        RPN rpn;
        int result = rpn.calculate(argv[1]);
        std::cout << result << std::endl;
    }
    catch(const std::runtime_error  &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}