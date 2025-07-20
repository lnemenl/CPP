#include "Serializer.hpp"
#include <cstdint>

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	if (raw == 0)
		return nullptr;
	return reinterpret_cast<Data*>(raw);
}

/*
	reinterpret cast is a C++ cast operator
	used to convert between unrelated types,
	such as a pointer (Data*) to an integer (uintptr_t) or vice versa.

	It’s low-level and potentially dangerous
	because it reinterprets the bit pattern without checking type compatibility.

	Syntax: reinterpret_cast<TargetType>(expression).
	Check for alignment (illustrative, platform-dependent)
    if (raw % alignof(Data) != 0)
        return nullptr; // Misaligned address, not valid for Data

	Alignment refers to how data is stored in memory.
	CPUs access memory more efficiently when data is stored at specific memory address boundaries
	(e.g., addresses divisible by 4 or 8 bytes).
	Each data type has an alignment requirement,
	which you can get using alignof(Type) in C++.
	For example:
	int typically requires 4-byte alignment (address must be divisible by 4).
	std::string or a struct like Data might require 8-byte alignment on a 64-bit system due to its members.
	If a pointer’s address isn’t aligned
	(e.g., not a multiple of alignof(Data)),
	it’s invalid for that type and could cause crashes or undefined behavior when dereferenced.

	Example:
	Suppose alignof(Data) == 8 (common for a struct with std::string on a 64-bit system).
	If raw = 1000 (divisible by 8: 1000 % 8 == 0), it’s aligned.
	If raw = 1001 (not divisible: 1001 % 8 == 1), it’s misaligned, so return nullptr.
*/