#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
	{
        std::cerr << "Error: Usage ./RPN <num> <num> <op>" << std::endl;
        return 1;
    }
    try
	{
        std::string expression = av[1];
        long long result = RPN::do_RPN(expression);
        std::cout << result << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
