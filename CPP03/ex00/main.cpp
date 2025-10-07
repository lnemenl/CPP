#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("pirate");
	b.attack("Target1");
	b.takeDamage(3);
	b.beRepaired(5);
	for (int i = 0; i < 11; ++i)
		b.attack("Target2");
	b.beRepaired(2);
	b.takeDamage(100);
	b.attack("Target3");
	b.beRepaired(10);
	ClapTrap c(b);
	a = b;
	a.attack("Target4");
	a.takeDamage(5);
	a.beRepaired(3);

	return 0;
}