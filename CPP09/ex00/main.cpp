#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage : ./btc input.txt" << std::endl;
        return (1);
    }
    try
    {
        BitcoinExchange btc("data.csv", true);
        // process input here eg: btc.processInput(argv[1])
        (void)argv;
        
    }
    catch(const std::exception &e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
}