#include <BitcoinExchange.hpp>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>


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