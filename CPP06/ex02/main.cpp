#include "Base.hpp"


int main()
{
    srand (time(NULL));
    Base *test = generate();
    Base *test2 = generate();
    std::cout << "| TEST |" << std::endl; 
    std::cout << "Type Pointer : "; identify(test);
    std::cout << "Type Reference : "; identify(*test);
    std::cout << "Type 2 Pointer : "; identify(test2);
    std::cout << "Type 2 Reference : "; identify(*test2);
}