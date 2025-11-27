#include "BitcoinExchange.hpp"


std::map<std::string,float> BitcoinExchange::LoadDatabase(const std::string &filename)
{
    std::map<std::string,float> prices;

    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Couldn't open the file");

    std::string line;
    std::getline(file, line);
    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string rate;
        std::getline(ss, date, ',');
        std::getline(ss, rate, ',');
        prices[date] = std::atof(rate.c_str());
    }
    return prices;
}