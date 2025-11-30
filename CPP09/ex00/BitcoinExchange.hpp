#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <string>


class BitcoinExchange
{
    public: 
        BitcoinExchange(const std::string &filename, bool debug);
        void ProcessInput(const std::string &filename);
        ~BitcoinExchange();
        void getRate(const std::string &date, double amount) const;

    private:
        std::map<std::string, float> _database;
        bool _debug;

        std::map<std::string,float> LoadDatabase(const std::string &filename);

};