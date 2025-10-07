//WIP

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : name(), FragTrap(hit_points)
{
	std::cout << "[DiamondTrap] Constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_trap")
{
	std::cout << "[DiamondTrap] Constructor with name called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj)
{
	std::cout << "[DiamondTrap] Copy Constructor called: copied " << obj.name << "into " << this->name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	if (this != &obj)
		ClapTrap::operator=(obj);
	std::cout << "[DiamondTrap] Copy assignment operator called: from " << obj.name << " to " << this->name << std::endl;
	return *this;
}

DiamondTrap:: ~DiamondTrap()
{
	std::cout << "[DiamondTrap] Destructor called for " << name << std::endl;
}
