#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <list>
#include <vector>

void printHeader(const std::string& title)
{
	std::cout << "\n=== " << title << " ===\n";
}

int main()
{
	{
		printHeader("Test 1: Basic stack operations");
		MutantStack<int> ms;
		ms.push(5);
		ms.push(17);
		std::cout << "Top element: " << ms.top() << " (expect 17)\n";
		ms.pop();
		std::cout << "After pop, size: " << ms.size() << " (expect 1)" << " and the element is " << ms.top() << std::endl;
		std::cout << "Empty? " << (ms.empty() ? "yes" : "no") << std::endl;
	}

	{
		printHeader("Test 2: Forward iteration (bottom -> top)");
		MutantStack<int> ms;
		for (int i = 1; i <= 5; ++i) ms.push(i); // pushes 1..5
		std::cout << "Contents: ";
		for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
			std::cout << *it << ' ';
		std::cout << "\n(expected 1 2 3 4 5)" << std::endl;
	}

	{
		printHeader("Test 3: Reverse iteration (top -> bottom)");
		MutantStack<int> ms;
		for (int i = 10; i <= 30; i += 10) ms.push(i); // 10,20,30
		std::cout << "Contents (reverse): ";
		for (MutantStack<int>::reverse_iterator rit = ms.rbegin(); rit != ms.rend(); ++rit)
			std::cout << *rit << ' ';
		std::cout << "\n(expected 30 20 10)" << std::endl;
	}

	{
		printHeader("Test 4: Const iteration");
		MutantStack<int> ms;
		for (int i = 1; i <= 3; ++i) ms.push(i); // 1,2,3
		const MutantStack<int>& cms = ms;
		std::cout << "Const contents: ";
		for (MutantStack<int>::const_iterator it = cms.begin(); it != cms.end(); ++it)
			std::cout << *it << ' ';
		std::cout << "\n(expected 1 2 3)" << std::endl;
	}

	{
		printHeader("Test 5: Empty stack iteration");
		MutantStack<int> ms;
		std::cout << "Iterating empty stack: ";
		for (auto it = ms.begin(); it != ms.end(); ++it)
			std::cout << *it << ' ';
		std::cout << "\n(expected nothing)" << std::endl;
	}

	{
		printHeader("Test 6: Copy and assignment");
		MutantStack<int> ms1;
		for (int i = 1; i <= 3; ++i) ms1.push(i); // 1,2,3
		MutantStack<int> ms2(ms1); // copy constructor
		MutantStack<int> ms3;
		ms3 = ms1; // copy assignment
		std::cout << "ms2 top: " << ms2.top() << "\n(expected 3)" << std::endl;
		std::cout << "ms3 size: " << ms3.size() << "\n(expected 3)" << std::endl;
	}

	{
		printHeader("Test 7: Different type (std::string)");
		MutantStack<std::string> ms;
		ms.push("hello");
		ms.push("world");
		std::cout << "Forward iteration: ";
		for (auto it = ms.begin(); it != ms.end(); ++it)
			std::cout << *it << ' ';
		std::cout << "\n(expected hello world)" << std::endl;
	}

	{
		printHeader("Test 8: Modify through iterator");
		MutantStack<int> ms;
		for (int i = 1; i <= 3; ++i) ms.push(i); // 1,2,3
		for (auto it = ms.begin(); it != ms.end(); ++it)
			*it *= 10;
		std::cout << "Modified contents: ";
		for (auto it = ms.begin(); it != ms.end(); ++it)
			std::cout << *it << ' ';
		std::cout << "\n(expected 10 20 30)" << std::endl;
	}

	{
		printHeader("Test 9: Interop with STL algorithms");
		MutantStack<int> ms;
		for (int i = 1; i <= 5; ++i) ms.push(i); // 1..5
		int sum = std::accumulate(ms.begin(), ms.end(), 0);
		std::cout << "Sum of elements: " << sum << "\n(expected 15)" << std::endl;
		auto found = std::find(ms.begin(), ms.end(), 3);
		std::cout << "Find(3): " << (found != ms.end() ? "found" : "not found") << "\n(expected found)" << std::endl;
		auto notfound = std::find(ms.begin(), ms.end(), 9);
		std::cout << "Find(9): " << (notfound != ms.end() ? "found" : "not found") << "\n(expected not found)" << std::endl;
	}

	{
		printHeader("Test 10: MutantStack with std::list");

		MutantStack<int, std::list<int>> ms_list;
		for (int i = 1; i <= 5; ++i) ms_list.push(i);

		std::cout << "MutantStack<std::list> contents: ";
		for (auto it = ms_list.begin(); it != ms_list.end(); ++it)
			std::cout << *it << ' ';
		std::cout << "\n(expected 1 2 3 4 5)" << std::endl;

		// std::list
		std::list<int> lst;
		for (int i = 1; i <= 5; ++i) lst.push_back(i);

		std::cout << "std::list contents:              ";
		for (auto it = lst.begin(); it != lst.end(); ++it)
			std::cout << *it << ' ';
		std::cout << "\n" << std::endl;
	}

	{
		printHeader("Test 11: MutantStack with std::vector as underlying container");

		MutantStack<int, std::vector<int>> ms_vec;
		for (int i = 1; i <= 5; ++i) ms_vec.push(i * 10);  // 10,20,30,40,50

		std::cout << "MutantStack<std::vector> contents: ";
		for (auto it = ms_vec.begin(); it != ms_vec.end(); ++it)
			std::cout << *it << ' ';
		std::cout << "\n(expected 10 20 30 40 50)" << std::endl;

		// std::vector
		std::vector<int> vec;
		for (int i = 1; i <= 5; ++i) vec.push_back(i * 10);

		std::cout << "std::vector contents:              ";
		for (auto it = vec.begin(); it != vec.end(); ++it)
			std::cout << *it << ' ';
		std::cout << "\n" << std::endl;
	}


	return 0;
}
