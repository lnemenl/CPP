#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(nullptr) {}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack() const
{
	if (weapon)
	{
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
	else
	{
		std::cout << name << " is unarmed and cannot attack" << std::endl;
	}
}
