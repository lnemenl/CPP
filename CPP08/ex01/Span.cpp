#include "Span.hpp"
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <exception>

Span::Span(unsigned int N) : _maxSize(N) {}

const char* Span::SpanIsFull::what() const noexcept
{
    return "Span is full :(";
}

const char* Span::NotEnoughNumbersForSpan::what() const noexcept
{
    return "Not enough numbers to perform a Span :(";
}

void Span::addNumber(int numberToAdd)
{
    if (_numbers.size() >= _maxSize)
        throw SpanIsFull();
    _numbers.push_back(numberToAdd);
}

unsigned int Span::longestSpan()
{
    if (_numbers.size() <= 1)
        throw NotEnoughNumbersForSpan();
    auto result = std::minmax_element(begin(_numbers), end(_numbers));
    long long span = static_cast<long long>(*result.second) - static_cast<long long>(*result.first);
    return static_cast<unsigned int>(span);
}

unsigned int Span::shortestSpan()
{
    if (_numbers.size() <= 1)
        throw NotEnoughNumbersForSpan();

    std::vector<int> sortedrvec = _numbers;
    std::sort(sortedrvec.begin(), sortedrvec.end());
    long long minSpan = static_cast<long long>(sortedrvec[1]) - static_cast<long long>(sortedrvec[0]);
    for (size_t i = 2; i < sortedrvec.size(); ++i)
    {
        long long currentSpan = static_cast<long long>(sortedrvec[i]) - static_cast<long long>(sortedrvec[i - 1]);
        if (currentSpan < minSpan)
        {
            minSpan = currentSpan;
        }
    }
    return static_cast<unsigned int>(minSpan);
}