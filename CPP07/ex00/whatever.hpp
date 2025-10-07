#pragma once

template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


template <typename T>
const T& min(const T& a, const T& b)
{
	return (a < b) ? a : b;
}


template <typename T>
const T& max(const T& a, const T& b)
{
	return (a > b) ? a : b;
}

/*
In C++, we primarily pass arguments by reference for two key reasons:

To modify the original variable. (like a link to Google docs VS sharing a copy of a Word doc)

To avoid making an expensive copy of a variable.

*/