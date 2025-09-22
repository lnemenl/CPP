#pragma once
#include <vector>
#include <deque>


class PmergeMe
{

	public:
		PmergeMe() = delete;
		~PmergeMe() = delete;
		PmergeMe(const PmergeMe&) = delete;
		PmergeMe& operator=(const PmergeMe&) = delete;

		static void sort(std::vector<int>& container);
		static void sort(std::deque<int>& container);
};
