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

/*
	"generate" returns a Base* that points to an A, B, or C object

	-std::srand expects an unsigned int as its seed
	-std::time is a C function with the signature time_t time(time_t* timer).
	-If you pass a valid pointer, it stores the time there and returns it.
	-If you pass nullptr it only returns the time.

	Without seeding (std::srand),
	std::rand would produce the same sequence every run,
	making generate predictable (e.g., always returning A).
*/