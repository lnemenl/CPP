#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		/*pointer, as HumanB may be unarmed*/
		Weapon* weapon;

	public:
		HumanB(std::string name);
		void setWeapon(Weapon& weapon);
		void attack() const;
};