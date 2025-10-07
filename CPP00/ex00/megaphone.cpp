#include <iostream>
#include <cstring>

int main (int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }

    for (int i = 1; i < ac; i++)
    {
        for (int j = 0; av[i][j] != '\0'; j++)
        {
            std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(av[i][j])));
        }
    }
    std::cout << std::endl;
    return (0);
}