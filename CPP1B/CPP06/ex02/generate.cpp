#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int r = std::rand() % 3;
	switch (r)
	{
		case 0: return new A();
		case 1: return new B();
		default: return new C();
	}
}

