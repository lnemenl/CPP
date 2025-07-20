#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

// Identifies the type of p using dynamic_cast with pointers
void identify(Base* p)
{
    // Check for null pointer to avoid undefined behavior
    if (p == nullptr)
    {
        std::cout << "Error: Null pointer" << std::endl;
        return;
    }
    // dynamic_cast<A*(p): Uses RTTI to check if p points to an A object.
	// Follows the object's vptr to its vtable,
	// which stores type info and virtual function pointers (e.g., ~A).
	// Returns A* if the type is A, else nullptr.
	// The if checks the result as a boolean (non-null = true).

    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

// Identifies the type of p using dynamic_cast with references, no pointers
void identify(Base& p)
{
    // (void)dynamic_cast<A&(p): Uses RTTI to check if p refers to an A object
	// via its vptr and vtable, which stores type info. Succeeds if the type is A, printing "A";
	// else throws std::bad_cast.
	// (void) discards the result, as we only check success/failure. No pointers used.

    try
    {
        (void)dynamic_cast<A&>(p);
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