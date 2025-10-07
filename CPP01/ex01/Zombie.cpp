#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed") {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie()
{
    std::cout << name << ": Destroyed" << "\n";
}

void Zombie::announce(void) const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;    
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
