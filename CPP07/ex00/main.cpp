#include "whatever.hpp"

int main()
{
    int value_1 = 6;
    int value_2 = 7;

    int value_3 = 10;
    int value_4 = 10;

    std::cout << "value_1 before swap: " << value_1 << std::endl;
    std::cout << "value_2 before swap: " << value_2 << std::endl;
    swap(value_1, value_2);
    std::cout << "value_1 after swap: " << value_1 << std::endl;
    std::cout << "value_2 after swap: " << value_2 << std::endl;
    std::cout << "smallest value : " << min(value_1, value_2) << std::endl;
    std::cout << "biggest value: " << max(value_1, value_2) << std::endl;
    std::cout << "Test 2" << std::endl;
    std::cout << "Equal min Test : " << min(value_3, value_4) << std::endl;
    std::cout << "Equal max Test : " << max(value_3, value_4) << std::endl;
}