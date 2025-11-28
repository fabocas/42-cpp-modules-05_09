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
        BitcoinExchange btc(true);
        btc.LoadDatabase(argv[1]);
        
    }
    catch(const std::exception &e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
}