#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
	{
        std::cerr << "Usage: ./btc <input file>" << std::endl;
        return 1; // Return a non-zero value to indicate an error occurred.
    }
    try
	{
        BitcoinExchange btc;
        btc.processInputFile(av[1]);
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
