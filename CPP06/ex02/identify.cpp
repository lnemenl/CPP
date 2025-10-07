#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

// Prints the type ("A", "B", or "C") of the object pointed to by p
// Uses dynamic_cast to safely check the real type at runtime, as p is Base* but could point to A, B, or C
void identify(Base* p)
{
    // Check for null pointer to avoid confusion if p is nullptr
    if (p == nullptr)
    {
        std::cout << "Error: Null pointer" << std::endl;
        return;
    }

    /*  Try casting to A*, B*, C* to find the real type; print when a cast succeeds
        When the program runs, generate() randomly picks A, B, or C.
        The compiler can’t know which one at compile-time (when the code is written).
        So, you need dynamic_cast to check the type while the program is running (runtime). */

    if (dynamic_cast<A*>(p)) // Is this Base* actually pointing to an A?
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) // Is this Base* actually pointing to B?
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) // Is this Base* actually pointing to C?
        std::cout << "C" << std::endl;
}

/*  Prints the type ("A", "B", or "C") of the object referenced by p
    Uses dynamic_cast with try-catch to check the real type at runtime without pointers,
    as p is Base& but refers to A, B, or C */

void identify(Base& p)
{
    // Try casting to A&; print "A" if it works, else catch the failure and try B&
    try
    {
        (void)dynamic_cast<A&>(p); // (void) ignores result, we just need to know if it’s an A, no need for A&
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}
}

/*
	Polymorphism:
	Polymorphism allows objects of derived classes (A, B, C) to be treated as objects of their base class (Base).

	"identify" determines the actual type

	dynamic_cast:
	A C++ cast operator used to safely convert a base class pointer or reference to a derived class pointer or reference at runtime.
	Requires a polymorphic type (a class with at least one virtual function).

	For Pointers (dynamic_cast<Derived*>(base)):
	Returns a pointer to the derived type if the object is of that type or a subclass.
	Returns nullptr if the cast fails.
	Example: dynamic_cast<A*>(p) returns an A* if p points to an A object, else nullptr.

	For References (dynamic_cast<Derived&>(base)):
	Returns a reference to the derived type if valid.
	Throws a std::bad_cast exception if the cast fails.
	Example: (void)dynamic_cast<A&>(p); succeeds if p is an A, else throws.
*/