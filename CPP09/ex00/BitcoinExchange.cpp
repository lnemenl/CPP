#include <BitcoinExchange.hpp>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <exception>


int ReadingTheInput()
{
    std::ifstream inFile("data.csv");
    if (inFile.fail())
    {
        std::cout << "Error: could not open the file" << std::endl;
        return (1);
    }
    std::string line;
    std::getline(inFile, line);

    
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