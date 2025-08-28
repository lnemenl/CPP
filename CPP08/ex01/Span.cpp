#include "Span.hpp"
#include <iostream>
#include <vector>
#include <numeric>

Span::Span(unsigned int N) : _maxSize(N) {}

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
    return (*result.second - *result.first);
}

// unsigned int Span::shortestSpan()
// {
//     if (_numbers.size() <= 1)
//         throw NotEnoughNumbersForSpan();

//     std::vector<int> sortedrvec = _numbers;
//     std::sort(sortedrvec.begin(), sortedrvec.end());
//     std::vector<int> differences(sortedrvec.size());
//     std::adjacent_difference(sortedrvec.begin(), sortedrvec.end(), differences.begin());
//     auto result = std::min_element(differences.begin() + 1, differences.end());
//     return (*result);
// }


const char* Span::SpanIsFull::what() const noexcept
{
    return "Span is full :(";
}

const char* Span::NotEnoughNumbersForSpan::what() const noexcept
{
    return "Not enough numbers to perform a Span :(";
}


unsigned int Span::shortestSpan()
{
    if (_numbers.size() <= 1)
        throw NotEnoughNumbersForSpan();

    std::vector<int> sortedrvec = _numbers;
    std::sort(sortedrvec.begin(), sortedrvec.end());
    unsigned int minSpan = sortedrvec[1] - sortedrvec[0];
    for (size_t i = 2; i < sortedrvec.size(); ++i)
    {
        unsigned int currentSpan = sortedrvec[i] - sortedrvec[i - 1];
        if (currentSpan < minSpan)
        {
            minSpan = currentSpan;
        }
    }
    return minSpan;
}