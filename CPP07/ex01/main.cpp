#include "iter.hpp"

template <typename T>

void printThings(const T& thing)
{
    std::cout << thing << std::endl;
}


void printSomethings(const int &sthing)
{
    std::cout << sthing << std::endl;
}

void printSomethingsNotConst(int &swthing)
{
    std::cout << swthing << std::endl;
}

int main()
{
    int arr[6] = {4,1,5,6,9,7};
    std::string arr2[3] = {"Joao Gostoso, Fabio Sigma, Caio Aura"};

    std::cout << "Test with Int" << std::endl; iter(arr, 6, printThings<int>);
    std::cout << "Test with double" << std::endl; iter(arr2, 3, printThings<std::string>);
    std::cout << "Test with Int" << std::endl; iter(arr, 6, printSomethings);
    std::cout << "Test with double" << std::endl; iter(arr, 3, printSomethingsNotConst);
}