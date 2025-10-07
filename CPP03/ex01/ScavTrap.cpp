#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap("Default")
{
	std::cout << "[ScavTrap] Constructor called for " << name << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "[ScavTrap] Constructor with name called for " << name << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap (obj)
{
	std::cout << "[ScavTrap] Copy Constructor called: copied " << obj.name << "into " << this->name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	if (this != &obj)
		ClapTrap::operator=(obj);
	std::cout << "[ScavTrap] Copy assignment operator called: from " << obj.name << " to " << this->name << std::endl;
	return *this;
}

ScavTrap:: ~ScavTrap()
{
	std::cout << "[ScavTrap] Destructor called for " << name << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hit_points == 0 || energy_points == 0)
	{
		std::cout << "ScavTrap " << name << " cannot attack. No hit points or energy points left." << std::endl;
		return ;
	}
	energy_points--;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;	  
}
