#include "Span.hpp"
#include <iostream>
#include <vector>
#include <numeric>

Span::Span(unsigned int N) : _maxSize(N) {}

void Span::addNumber(int numberToAdd)
{
    if (_numbers.size() >= _maxSize)
        throw std::out_of_range("Cannot add number: Span is full");
    _numbers.push_back(numberToAdd);
}

unsigned int Span::longestSpan()
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("Cannot find span with less than two numbers");
    auto result = std::minmax_element(begin(_numbers), end(_numbers));
    return (*result.second - *result.first);
}

unsigned int Span::shortestSpan()
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("Cannot find span with less than two numbers");
    std::vector<int> temp_vec = _numbers;
    std::sort(temp_vec.begin(), temp_vec.end());
    unsigned int minSpan = temp_vec[1] - temp_vec[0];
    for (size_t i = 2; i < temp_vec.size(); ++i)
    {
        unsigned int currentSpan = temp_vec[i] - temp_vec[i - 1];
        if (currentSpan < minSpan)
        {
            minSpan = currentSpan;
        }
    }
    return minSpan;
}