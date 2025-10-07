#pragma once
#include <iostream>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce() const;

	private:
		std::string name;
};

Zombie* newZombie(std::string name); //Returns pointer to heap-allocated Zombie
void randomChump(std::string name); //Creates stack Zombie and calls announce