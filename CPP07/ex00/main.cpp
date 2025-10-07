#include "whatever.hpp"
#include <iostream>
#include <string>

void run_tests()
{
	std::cout << "--- Testing with integers ---" << std::endl;
	int a = 21;
	int b = 42;
	std::cout << "Initial: a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) is " << min(a, b) << std::endl;
	std::cout << "max(a, b) is " << max(a, b) << std::endl;

	std::cout << "\n--- Testing with strings ---" << std::endl;
	std::string c = "one";
	std::string d = "two";
	std::cout << "Initial: c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) is " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) is " << ::max(c, d) << std::endl;

	std::cout << "\n--- Edge Case: Testing with equal values ---" << std::endl;
	int e = 100;
	int f = 100;
	std::cout << "Initial: e = " << e << ", f = " << f << std::endl;
	::swap(e, f);
	std::cout << "After swap: e = " << e << ", f = " << f << std::endl;
	// The requirement says to return the second if they are equal
	std::cout << "min(e, f) address: " << &min(e, f) << std::endl;
	std::cout << "f address:         " << &f << std::endl;
	std::cout << "max(e, f) address: " << &max(e, f) << std::endl;
	std::cout << "f address:         " << &f << std::endl;


	std::cout << "\n--- Edge Case: Testing with pointers ---" << std::endl;
	int val1 = 1, val2 = 2;
	int* ptr1 = &val1;
	int* ptr2 = &val2;
	std::cout << "Initial pointers: ptr1 -> " << *ptr1 << ", ptr2 -> " << *ptr2 << std::endl;
	::swap(ptr1, ptr2); // Swaps the pointers, not the values they point to
	std::cout << "After swap: ptr1 -> " << *ptr1 << ", ptr2 -> " << *ptr2 << std::endl;
}

int main()
{
	run_tests();
	return 0;
}
