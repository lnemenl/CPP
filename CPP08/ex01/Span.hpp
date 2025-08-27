#pragma once

#include <exception>
#include <algorithm>
#include <vector>
#include <numeric> // for adjucent_difference
#include <iterator> // for distance

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

		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end);

		unsigned int shortestSpan();

		unsigned int longestSpan();

		class SpanIsFull : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class NotEnoughNumbersForSpan : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};


template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	if (std::distance(begin, end) + _numbers.size() > _maxSize)
		throw SpanIsFull();
	_numbers.insert(_numbers.end(), begin, end);
}