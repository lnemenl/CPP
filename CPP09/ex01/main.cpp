#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
	{
        std::cerr << "Usage:" << std::endl;
        return 1; // Return a non-zero value to indicate an error occurred.
    }
    try
	{
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
