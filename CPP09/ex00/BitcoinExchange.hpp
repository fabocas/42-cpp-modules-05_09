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
        BitcoinExchange(bool Debug);
        std::map<std::string,float> LoadDatabase(const std::string &filename);
        

    private:
        std::map<std::string, float> _database;
        bool Debug;


};