#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &filename, bool debug) : _debug(debug)
{
    _database = LoadDatabase(filename);
};

BitcoinExchange::~BitcoinExchange(){};


void BitcoinExchange::getRate(const std::string &date, double amount) const
{
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
    if (it == _database.begin() && it->first != date)
    {
        std::cerr << "Error: no date found for " << date << std::endl;
        return;
    }
    //if the exact same date isnt found we decrement
    if (it == _database.end() || it->first != date)
        --it;
    // BTC conversion: user amount times the historical rate
    double result = amount * it->second;
    std::cout << date << " => " << amount << " = " << result << std::endl;

}
static bool isFutureDate(int y, int m, int d)
{
    time_t t = time(NULL);
    tm *now = localtime(&t);

    int cy = now->tm_year + 1900;
    int cm = now->tm_mon + 1;
    int cd = now->tm_mday;

    if (y > cy)
        return true;
    if (y == cy && m > cm)
        return true;
    if (y == cy && m == cm && d > cd)
        return true;
    return false;
}

static bool isValidRate(const std::string &string, double &value)
{
    char* endptr;
    const char* str  = string.c_str();

    while (*str == ' ' || *str == '\t')
        str++;
    if (*str == '\0')
        return false;
    value = strtod(str, &endptr);
    if (endptr == str)
        return false;
    while (*endptr == ' ' || *endptr == '\t')
        endptr++;
    if (*endptr != '\0')
        return false;
    if (value < 0 || value > 1000)
        return false;
    return true;
}
static bool isValidDate(const std::string &date)
{
    if (date.length() != 10)
    {
        std::cerr << "Invalid length of date" << std::endl;
        return false;
    }
    if (date[4] != '-' || date[7] != '-')
    {
        std::cerr << "the - was not found" << std::endl;
        return false;
    }
    int y = atoi(date.substr(0, 4).c_str());
    int m = atoi(date.substr(5, 2).c_str());
    int d = atoi(date.substr(8, 2).c_str());
    if (isFutureDate(y, m, d))
    {
        std::cerr << "Error: date is in the future => " << date << std::endl;
        return false;
    }
    if (m < 1 || m > 12)
    {
        std::cerr << "Invalid month" << std::endl;
        return false;
    }
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    int maxDay = daysInMonth[m - 1];
    if (m == 2 && leap) maxDay = 29;
    if (d < 1 || d > maxDay)
    {
        std::cerr << "Invalid Day of the month" << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::ProcessInput(const std::string &filename)
{
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
        size_t pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cerr  << "Error bad input => " << line << std::endl;
            continue;
        }
        date = line.substr(0, pos);
        date.erase(0, date.find_first_not_of(" \t\r\n"));
        date.erase(date.find_last_not_of(" \t\r\n") + 1);
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => '" << line
                << "' => No Seperator '|' found." << std::endl;
            continue; 
        }
        double BtcRate;
        rate = line.substr(pos + 1);
        rate.erase(0, rate.find_first_not_of(" \t\r\n"));
        rate.erase(rate.find_last_not_of(" \t\r\n") + 1);
        if (!isValidRate(rate, BtcRate))
        {
            std::cerr << "Error: bad input => " << rate << std::endl;
            continue;
        }
        getRate(date, BtcRate);
    }
}
std::map<std::string, float> BitcoinExchange::LoadDatabase(const std::string &filename)
{
    std::map<std::string, float> prices;

    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Couldn't open the file => " + filename);
    std::string line;
    std::getline(file, line);
    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string rate;

        std::getline(ss, date, ',');
        std::getline(ss, rate);
        double value;
        isValidRate(rate, value);
        prices[date] = value;
        if (_debug)
        {
            std::cout << date << " => " << prices[date] << std::endl;
        }
    }
    return prices;
}
