#include <BitcoinExchange.hpp>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <exception>


BitcoinExchange::BitcoinExchange()
{
    try
    {
        this->loadDatabase();
    }
    catch(const std::exception& e)
    {
        throw;
    }
}

void BitcoinExchange::loadDatabase()
{
    std::ifstream dbFile("data.csv");
    if (!dbFile.fail())
        throw std::runtime_error("Error could not open database file 'data.csv'");
    std::string line;
    std::getline(dbFile, line);
    if (line != "data,exchange_rate")
        throw std::runtime_error("Error: invalid database header");
    while (std::getline(dbFile, line))
    {
        this->parseDatabaseLine(line);
    }
    if (_data.empty())
        throw std::runtime_error("Error: database is empty or invalid");
}

// Parsing a single line from a database
void BitcoinExchange::parseDatabaseLine(const std::string& line)
{
    std::stringstream stst(line);
    std::string dataPart;
    std::string ratePart;

    if (std::getline(stst, dataPart, ',') && std::getline(stst, ratePart))
    {
        try
        {
            float rate = std::stof(ratePart);
            _data[dataPart] = rate;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: could not parse database line:" << line << std::endl;
        }
    }
}