#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default")
{
	std::cout << "[FragTrap] Constructor called for " << name << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "[FragTrap] Constructor with name called for " << name << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap (obj)
{
	std::cout << "[FragTrap] Copy Constructor called: copied " << obj.name << "into " << this->name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	if (this != &obj)
		ClapTrap::operator=(obj);
	std::cout << "[FragTrap] Copy assignment operator called: from " << obj.name << " to " << this->name << std::endl;
	return *this;
}

FragTrap:: ~FragTrap()
{
	std::cout << "[FragTrap] Destructor called for " << name << std::endl;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "🫸 🫷" << std::endl;
}
