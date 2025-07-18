#include "Base.hpp"
#include <iostream>

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main()
{
	Base* obj = generate();

	std::cout << "identify(*): ";
	identify(obj);

	std::cout << "identify(&): ";
	identify(*obj);

	delete obj;
	return 0;
}