#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./harlfilter <level>" << std::endl;
		return (1);
	}
	
	Harl harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	for (; i < 4; i++)
	{
		if (av[1] == levels[i])
		break;
	}
	
	switch (i)
	{
	case 0:
		harl.complain("DEBUG");
	case 1:
		harl.complain("INFO");
	case 2:
		harl.complain("WARNING");
	case 3:
		harl.complain("ERROR");
		break;
	default:
		std::cout << "[Harl] invalid level: " << av[1] << std::endl;
	}
	return (0);
}
