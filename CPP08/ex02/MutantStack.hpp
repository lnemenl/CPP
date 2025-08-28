#pragma once

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
    public:
        using iterator = typename Container::iterator;
        using const_iterator = typename Container::const_iterator;
        using reverse_iterator = typename Container::reverse_iterator;
        using const_reverse_iterator = typename Container::const_reverse_iterator;

        MutantStack() = default;
        ~MutantStack() = default;
        MutantStack(const MutantStack&) = default;
        MutantStack& operator=(const MutantStack&) = default;

        iterator begin() { return <Container&>(*this).begin(); }
        iterator end() { return <Container&>(*this).end(); }

        const_iterator begin() const { return <Container&>(*this).begin(); }
        const_iterator end() const { return <Container&>(*this).end(); }

        reverse_iterator rbegin() { return <Container&>(*this).rbegin(); }
        reverse_iterator rend() { return <Container&>(*this).rend(); }

        const_reverse_iterator rbegin() const { return <Container&>(*this).rbegin(); }
        const_reverse_iterator rend() const { return <Container&>(*this).rend(); }
};
