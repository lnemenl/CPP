#pragma once

#include <cstddef>      // for size_t
//#include <stdexcept>    // for std::out_of_range

template <typename T>
class Array
{
	private:
		T*		_data;	// Raw pointer to dynamic array
		size_t	_size;	// Number of elements

	public:
		// Default constructor: Empty array
		Array() : _data(nullptr), _size(0) {}

		// Size constructor
		Array(size_t n) : _data(new T[n]()), _size(n) {}

		// Destructor
		~Array() { delete[] _data; }

		// Copy constructor, deep copy
		Array(const Array& other) : _data(new T[other._size]()), _size(other._size)
		{
			for (size_t i = 0; i < _size; ++i)
			{
				_data[i] = other._data[i];
			}
		}

		// Copy assignment: Copy-and-swap idiom, but manual swap (no std::swap)
		Array& operator=(const Array& other)
		{
			if (this == &other) return *this;	// self-assignment

			Array temp(other);	// Make a deep copy
			// Manual swap:
			T* old_data = _data;
			size_t old_size = _size;
			_data = temp._data;
			_size = temp._size;
			temp._data = old_data;
			temp._size = old_size;

			return *this;
    }

	// Adding the missing part for the rule of FIVE (move constructor, nove assignment + [])
};