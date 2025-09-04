#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: btc <input file>" << std::endl;
		return (1);
	}

	std::string filename = av[1];

	std::ifstream inFile(filename);
	if (inFile.fail())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	inFile.close();
	return (0);
}
