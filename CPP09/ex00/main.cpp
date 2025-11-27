#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage : ./BitcoinExc database.csv" << std::endl;
        return (1);
    }
    try
    {
        BitcoinExchange btc;
        btc.LoadDatabase(argv[1]);
    }
    catch(...)
    {

    }
}