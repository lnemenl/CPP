#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <ctime> // clock
#include <iomanip> // setprecision

// Printing container with prefix, truncating large ones
template <typename Container>
void print_container(const std::string& prefix, const Container& container)
{
	std::cout << prefix;
	const size_t limit = 10;
	if (container.size() > limit)
	{
		auto it = container.begin();
		for (size_t i = 0; i < limit; ++i, ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << "[...]";
	}
	else
	{
		for (int val : container)
		{
			std::cout << val << " ";
		}
	}
	std::cout << std::endl;
}

// Parsing and validating args to vector. Ensuring positive ints
bool parse_and_validate(int argc, char** argv, std::vector<int>& data)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg(argv[i]);
		if (arg.find_first_not_of("0123456789") != std::string::npos || arg.empty())
		{
			std::cerr << "Error: Invalid input '" << arg << "'." << std::endl;
			return false;
		}
		try
		{
			long long val = std::stoll(arg);
			if (val > std::numeric_limits<int>::max() || val <= 0)
			{
				std::cerr << "Error: Invalid positive integer '" << arg << "'." << std::endl;
				return false;
			}
			data.push_back(static_cast<int>(val));
		}
		catch (...)
		{
			std::cerr << "Error: Invalid format '" << arg << "'." << std::endl;
			return false;
		}
	}
	if (data.empty())
	{
		std::cerr << "Error: No numbers provided." << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <positive_integers>" << std::endl;
		return 1;
	}

	std::vector<int> data;
	if (!parse_and_validate(argc, argv, data))
	{
		return 1;
	}

	std::deque<int> deque_data(data.begin(), data.end());

	print_container("Before: ", data);

	clock_t start_vec = clock();
	PmergeMe::sort(data);
	clock_t end_vec = clock();
	double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

	clock_t start_deq = clock();
	PmergeMe::sort(deque_data);
	clock_t end_deq = clock();
	double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC;

	print_container("After:  ", data);

	std::cout << "Time to process a range of " << data.size() << " elements with std::vector : "
			  << std::fixed << std::setprecision(5) << time_vec << " s" << std::endl;
	std::cout << "Time to process a range of " << data.size() << " elements with std::deque  : "
			  << std::fixed << std::setprecision(5) << time_deq << " s" << std::endl;

	return 0;
}