#pragma once

#include <stdexcept>
#include <algorithm>
#include <vector>

class Span
{
	private:
		unsigned int        _maxSize;
		std::vector<int>    _numbers;
	public:
		Span(unsigned int N);
		~Span() = default;
		Span(const Span&) = default;
		Span& operator=(const Span&) = default;

		void addNumber(int numberToAdd);
		unsigned int shortestSpan();
		unsigned int longestSpan();
};