#include "PmergeMe.hpp"

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <sstream>
#include <ctime> // for timing
#include <cstdlib>

bool is_number(const std::string &s)
{
    for (size_t i = 0; i < s.length(); i++)
        if (!isdigit(s[i]))
            return false;
    return true;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe <numbers...>\n";
        return 1;
    }

    std::vector<int> numbers;
    std::set<int> check_duplicates;

    // Parse and validate input
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if (!is_number(arg))
        {
            std::cerr << "Error: all arguments must be positive integers.\n";
            return 1;
        }
        int num = atoi(arg.c_str());
        if (check_duplicates.count(num))
        {
            std::cerr << "Error: duplicate numbers not allowed.\n";
            return 1;
        }
        check_duplicates.insert(num);
        numbers.push_back(num);
    }

    // Copy into vector and deque
    std::vector<int> vec(numbers.begin(), numbers.end());
    std::deque<int> deq(numbers.begin(), numbers.end());

    // Print original sequence
    std::cout << "Before: ";
    for (size_t i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << "\n";

    // Sort vector
    clock_t start = clock();
    PmergeMe::sortVector(vec);
    clock_t end = clock();
    double time_vector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // microseconds
    std::cout << "After vector sort: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << "\nTime to process a range of " << vec.size() << " elements with std::vector : "
              << time_vector << " ms\n";

    // Sort deque
    start = clock();
    PmergeMe::sortDeque(deq);
    end = clock();
    double time_deque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // microseconds
    std::cout << "After deque sort: ";
    for (size_t i = 0; i < deq.size(); i++)
        std::cout << deq[i] << " ";
    std::cout << "\nTime to process a range of " << deq.size() << " elements with std::deque : "
              << time_deque << " ms\n";

    return 0;
}
