#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(bool Debug) : Debug(Debug) {
                                               };

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

static bool isValidRate(const std::string &rate)
{
    //TO DO check if rate is a number, check if its valid, check if is missing etc

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

std::map<std::string, float> BitcoinExchange::LoadDatabase(const std::string &filename)
{
    std::map<std::string, float> prices;

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
        if (!std::getline(ss, date, ',') || !std::getline(ss, rate))
            throw std::runtime_error("Bad line format");
        if (!isValidDate(date))
            throw std::runtime_error("Invalid Date : " + date);
        float value = std::atof(rate.c_str());
        if (value < 0)
            throw std::runtime_error("Invalid value rate: " + rate);
        prices[date] = value;
        if (Debug)
        {
            std::cout << date << " => " << prices[date] << std::endl;
        }
    }
    return prices;
}