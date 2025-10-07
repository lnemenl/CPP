#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed") {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie()
{
    std::cout << name << ": Destroyed" << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/*
    The syntax name("Unnamed") initializes the name member
    variable directly, which is more efficient than assigning
    it in the constructor body (e.g., name = "Unnamed";)
    because it avoids creating a temporary object
    and performing an assignment.

    Initializer lists are preferred
    because they initialize members directly,
    before the constructor body runs,
    which is more efficient than assignment in the body.
*/
