#pragma once

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        //
        // Give me the iterator type of whatever container std::stack<T> is using
        using iteraror = typename std::stack<T>::container_type::iterator;
        using const_iterator = typename std::stack<T>::container_type::const_iterator;
        using reverse_iterator = typename std::stack<T>::container_type::reverse_iterator;
        using const_reverse_iterator = typename std::stack<T>::container_type::const_reverse_iterator;

        MutantStack() = default;
        ~MutantStack() = default;
        MutantStack(const MutantStack&) = default;
        MutantStack& operator=(const MutantStack&) = default;
};