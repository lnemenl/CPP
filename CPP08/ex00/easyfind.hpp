#pragma once
#include <algorithm>
#include <stdexcept>


template <typename T>
auto easyfind(T&& container, int value)
// The use of a forwarding reference (T&&) allows
// function to accept any kind of container
{
	auto it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) throw std::runtime_error("Value not found in container");
	return it;
}



/*
	The rules:

	& + &   →   &   (An lvalue-ref to an lvalue-ref becomes an lvalue-ref)
	& + &&  →   &   (An lvalue-ref to an rvalue-ref becomes an lvalue-ref)
	&& + &  →   &   (An rvalue-ref to an lvalue-ref becomes an lvalue-ref)
	&& + && →   &&  (An rvalue-ref to an rvalue-ref becomes an rvalue-ref)
	The simple takeaway is: if a single & (lvalue reference) appears anywhere in the combination, the final result is a single &.

*/