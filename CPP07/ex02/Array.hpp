#pragma once
#include <iostream> // temporary, for demostration purpose

#include <cstddef>      // for size_t
#include <stdexcept>    // for std::out_of_range

template <typename T>
class Array
{
	private:
		T*		_data;
		size_t	_size;

	public:
		// Default constructor
		Array() : _data(nullptr), _size(0) { std::cout << "Default Constructor\n"; }
		//Array() : _data(nullptr), _size(0) {}

		// Size constructor
		Array(size_t n) : _data(new T[n]()), _size(n) { std::cout << "Sizing Constructor (" << n << ")\n"; }
		// Array(size_t n) : _data(new T[n]()), _size(n) {} // The () after [n] ensures elements are initialized to default values (0 for int, empty for string).

		// Copy constructor
		Array(const Array& source) : _data(new T[source._size]()), _size(source._size)
		{
			std::cout << "COPY Constructor\n";
			for (size_t i = 0; i < _size; ++i)
			{
				_data[i] = source._data[i];
			}
		}

		// Copy assignment (copy-and-swap idiom)
		Array& operator=(const Array& source)
		{
			std::cout << "COPY Assignment\n";
			Array temp(source); // Deep copy, full copy of the source
			// Manual swap
			T* old_data = _data;
			size_t old_size = _size;
			_data = temp._data;
			_size = temp._size;
			temp._data = old_data;
			temp._size = old_size;
			return *this; // temp destructs, freeing old data
		}

		// Move constructor. Steals the resource from a temporary object
		Array(Array&& source) noexcept : _data(source._data), _size(source._size)
		// called when creating from a temporary. Copy the pointer, null out the source. No allocation.
		{
			std::cout << "MOVE Constructor\n";
			source._data = nullptr;
			source._size = 0;
		}

		// Move assignment operator. Steals the resource from a temporary object to assign to an existing one
		Array& operator=(Array&& source) noexcept // sourse is rvalue reference to the temporary
		{
			std::cout << "MOVE Assignment\n";
			if (this != &source)
			{
				delete[] _data; // deleting current pointer
				_data = source._data; // taking the source's pointer
				_size = source._size;
				source._data = nullptr; // null out the sourse
				source._size = 0;
			}
			return *this; // this is a pointer to the left object
		}

		// Destructor
		~Array()
		{
			std::cout << "Destructor\n";
			delete[] _data;
		}

		// Subscript operator
		T& operator[](size_t index)
		{
			if (index >= _size)
			{
				throw std::out_of_range("Index out of range");
			}
			return _data[index];
		}

		const T& operator[](size_t index) const
		{
			if (index >= _size)
			{
				throw std::out_of_range("Index out of range");
			}
			return _data[index];
		}

		// Size getter
		size_t size() const
		{
			return _size;
		}
};

// Temporaries are created when returning by value or in expressions. They are rvalues, allowing move.
