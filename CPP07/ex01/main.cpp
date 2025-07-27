#include "iter.hpp"
#include <iostream>
#include <string>

// A simple function template to print any element
template <typename T>
void printElement(const T& element) { std::cout << element << " "; }

// A function to increment integer elements
void increment(int& n) { n++; }

void run_tests()
{
	std::cout << "--- Test with an array of integers ---" << std::endl;
	int int_array[] = {1, 2, 3, 4, 5};
	::iter(int_array, 5, ::printElement<int>);
	std::cout << std::endl;

	std::cout << "\n--- Test with a modifying function ---" << std::endl;
	::iter(int_array, 5, ::increment);
	std::cout << "After incrementing: ";
	::iter(int_array, 5, ::printElement<int>);
	std::cout << std::endl;

	std::cout << "\n--- Test with an array of strings ---" << std::endl;
	std::string str_array[] = {"one", "two", "three"};
	::iter(str_array, 3, ::printElement<std::string>);
	std::cout << std::endl;

	std::cout << "\n--- Edge Case: Testing with an empty array (length 0) ---" << std::endl;
	int empty_array[] = {};
	std::cout << "Calling iter on empty array... ";
	::iter(empty_array, 0, ::printElement<int>);
	std::cout << "Done." << std::endl;

	std::cout << "\n--- Edge Case: Testing with a null pointer ---" << std::endl;
	std::cout << "Calling iter on nullptr... ";
	::iter<int>(nullptr, 5, ::printElement<int>); // Length doesn't matter if ptr is null
	std::cout << "Done." << std::endl;
}

int main()
{
	::run_tests();
	return 0;
}