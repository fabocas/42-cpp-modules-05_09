#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <ctime>


class BitcoinExchange
{
    public: 
        BitcoinExchange(const std::string &filename, bool debug);
        void ProcessInput(const std::string &filename);
        ~BitcoinExchange();

    private:
        std::map<std::string, float> _database;
        bool _debug;

        std::map<std::string,float> LoadDatabase(const std::string &filename);

};