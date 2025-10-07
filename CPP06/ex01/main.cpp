#include "Serializer.hpp"
#include <iostream>
#include <limits>

int main()
{
    // Test 1: Null pointer
    uintptr_t null_raw = Serializer::serialize(nullptr);
    Data* null_deserialized = Serializer::deserialize(null_raw);
    std::cout << "Null pointer test: " << (null_deserialized == nullptr ? "✅ Passed" : "❌ Failed") << std::endl;

    // Test 2: Valid Data object
    Data original { 42, "hello" };
    uintptr_t raw = Serializer::serialize(&original);
    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Original:     " << &original << " -> id: " << original.id << ", name: " << original.name << std::endl;
    std::cout << "Deserialized: " << deserialized << " -> id: " << deserialized->id << ", name: " << deserialized->name << std::endl;

    if (deserialized == &original)
        std::cout << "✅ Pointer match verified.\n";
    else
        std::cout << "❌ Pointer mismatch!\n";

    // Test 3: Extreme int value
    Data extreme { std::numeric_limits<int>::max(), "max_int" };
    uintptr_t extreme_raw = Serializer::serialize(&extreme);
    Data* extreme_deserialized = Serializer::deserialize(extreme_raw);

    std::cout << "Extreme:     " << &extreme << " -> id: " << extreme.id << ", name: " << extreme.name << std::endl;
    std::cout << "Extreme Deserialized: " << extreme_deserialized << " -> id: " << extreme_deserialized->id << ", name: " << extreme_deserialized->name << std::endl;

    if (extreme_deserialized == &extreme)
        std::cout << "✅ Extreme pointer match verified.\n";
    else
        std::cout << "❌ Extreme pointer mismatch!\n";

    return 0;
}
