#pragma once
#include <algorithm> // find
#include <stdexcept>


template <typename T>
auto easyfind(T& container, int value)
{
	auto it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
	return it;
}

template <typename T>
auto easyfind(const T& container, int value)
{
	auto it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
	return it;
}