#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data original { 42, "hello" };

	uintptr_t raw = Serializer::serialize(&original);
	Data* deserialized = Serializer::deserialize(raw);

	std::cout << "Original:     " << &original << " -> id: " << original.id << ", name: " << original.name << std::endl;
	std::cout << "Deserialized: " << deserialized << " -> id: " << deserialized->id << ", name: " << deserialized->name << std::endl;

	if (deserialized == &original)
		std::cout << "✅ Pointer match verified.\n";
	else
		std::cout << "❌ Pointer mismatch!\n";

	return (0);
}
