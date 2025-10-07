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
		using std::stack<T, Container>::c;

		MutantStack() = default;
		~MutantStack() = default;
		MutantStack(const MutantStack&) = default;
		MutantStack& operator=(const MutantStack&) = default;

		iterator begin() { return c.begin(); }
		iterator end() { return c.end(); }

		const_iterator begin() const { return c.begin(); }
		const_iterator end() const { return c.end(); }

		reverse_iterator rbegin() { return c.rbegin(); }
		reverse_iterator rend() { return c.rend(); }

		const_reverse_iterator rbegin() const { return c.rbegin(); }
		const_reverse_iterator rend() const { return c.rend(); }
};

/*
	using std::stack<T, Container>::c; means:
	"Take the thing named c from std::stack (the parent),
	and make it directly visible here in MutantStack (the child),
	so I can just write c instead of this->c."
	
	“bring an existing name from the parent into the child’s scope.”
*/