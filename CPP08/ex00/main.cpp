#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Helper function to print a container
template <typename T>
void printContainer(const T& container, const std::string& name)
{
	std::cout << name << " contains: ";
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main()
{
	// === TEST 1: std::vector - Non-const version ===
	// EXPECTATION: Find the value and be able to modify it.
	std::cout << "--- TEST 1: Mutable std::vector ---" << std::endl;
	std::vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	numbers.push_back(40);
	printContainer(numbers, "Initial vector");
	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 30);
		std::cout << "Found value: " << *it << std::endl;
		std::cout << "Modifying found value to 99..." << std::endl;
		*it = 99; // This should work because 'it' is a mutable iterator
		printContainer(numbers, "Modified vector");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	// === TEST 2: std::vector - Const version ===
	// PURPOSE: Test with a const vector to ensure const-correctness.
	// EXPECTATION: Find the value but be unable to modify it (compile error).
	std::cout << "--- TEST 2: Const std::vector ---" << std::endl;
	const std::vector<int> const_numbers(numbers.begin(), numbers.end());
	printContainer(const_numbers, "Const vector");
	try
	{
		std::vector<int>::const_iterator it = easyfind(const_numbers, 99);
		std::cout << "Found value: " << *it << std::endl;

		// The line below will NOT compile, which PROVES our function is const-correct.
		// *it = 100;
		std::cout << "Value cannot be modified through const_iterator (Correct!)." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	// === TEST 3: Exception Handling ===
	// PURPOSE: Test the case where the value is not found.
	// EXPECTATION: The function should throw an exception.
	std::cout << "--- TEST 3: Not Found Exception ---" << std::endl;
	printContainer(numbers, "Searching in");
	try
	{
		std::cout << "Searching for value 123 (which does not exist)..." << std::endl;
		easyfind(numbers, 123);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Successfully caught expected exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	// === TEST 4: Different Container Type (std::list) ===
	// PURPOSE: Prove the template works with other STL containers.
	// EXPECTATION: Should work exactly the same as with std::vector.
	std::cout << "--- TEST 4: std::list Container ---" << std::endl;
	std::list<int> number_list;
	number_list.push_back(5);
	number_list.push_back(15);
	number_list.push_back(25);
	printContainer(number_list, "Initial list");
	try
	{
		std::list<int>::iterator it = easyfind(number_list, 15);
		std::cout << "Found value in list: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	// === TEST 5: Edge Cases ===
	// PURPOSE: Test finding the first and last elements, and an empty container.
	// EXPECTATION: Find first/last correctly. Throw on empty.
	std::cout << "--- TEST 5: Edge Cases ---" << std::endl;
	printContainer(numbers, "Searching in");
	try
	{
		std::cout << "Finding first element (10)... Found: " << *easyfind(numbers, 10) << std::endl;
		std::cout << "Finding last element (40)... Found: " << *easyfind(numbers, 40) << std::endl;
		
		std::vector<int> empty_vec;
		printContainer(empty_vec, "Searching in empty vector");
		std::cout << "Searching for 42 in empty vector..." << std::endl;
		easyfind(empty_vec, 42);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Successfully caught expected exception for empty vector: " << e.what() << std::endl;
	}
	std::cout << "\nAll tests completed." << std::endl;

	return 0;
}