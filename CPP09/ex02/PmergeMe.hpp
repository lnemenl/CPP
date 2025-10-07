#pragma once
#include <vector>
#include <deque>


class PmergeMe
{
	public:
		PmergeMe() = delete;
		~PmergeMe() = default;
		PmergeMe(const PmergeMe&) = default;
		PmergeMe& operator=(const PmergeMe&) = default;

		static void sort(std::vector<int>& container);
		static void sort(std::deque<int>& container);
};