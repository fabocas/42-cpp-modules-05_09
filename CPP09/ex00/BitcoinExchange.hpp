#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>


class BitcoinExchange
{
    public: 
        BitcoinExchange();
        std::map<std::string,float> LoadDatabase(const std::string &filename);

    private:
        std::map<std::string, float> _database;


};