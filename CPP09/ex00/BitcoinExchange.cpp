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

BitcoinExchange::~BitcoinExchange() {};

void BitcoinExchange::loadDatabase()
{
    std::ifstream dbFile("data.csv");
    if (dbFile.fail())
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

void BitcoinExchange::processInputFile(const std::string& filename)
{
    std::ifstream inputFile(filename);
    if (inputFile.fail())
    {
        std::cerr << "Error: could not open the file" << std::endl;
        return;
    }

    std::string line;
    std::getline(inputFile, line);
    if (line != "date | value")
    {
        std::cerr << "Warning: Invalid header in the input file" << std::endl;
        //continuing with processing the line
    }

    while (std::getline(inputFile, line))
    {
        this->//processing the line
    }
}


bool BitcoinExchange::isValidValue(float value) const
{
    if (value < 0)
    {
        std::cerr << "Error: number is not positive" << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cerr << "Error: number is too large" << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& dateStr) const
{
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-') return false;
    try
    {
        int year = std::stoi(dateStr.substr(0, 4));
        int month = std::stoi(dateStr.substr(5,2));
        int day = std::stoi(dateStr.substr(8,2));
        if (month < 1 || month > 12 || day < 1 || day > 31) return false;
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
        if (month == 2)
        {
            bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if ((isLeap && day > 29) || (!isLeap && day > 28)) return false;
        }
    }
    catch (...)
    {
        return false;
    }
    return true;
}
