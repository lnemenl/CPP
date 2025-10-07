#pragma once
#include <iostream>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce() const;
		void setName(std::string name);
		
	private:
		std::string name;
};

Zombie* zombieHorde(int N, std::string name);