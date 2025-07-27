#pragma once
#include <cstddef> // For size_t

/**
 * @brief Applies a function to each element of an array.
 * @details Iterates from index 0 to length-1, calling the function f on each
 * element. Includes a null-check on the array pointer for safety.
 * @tparam T The type of the elements in the array.
 * @tparam Func The type of the function to apply.
 * @param array Pointer to the start of the array. Can be nullptr.
 * @param length The number of elements in the array.
 * @param f The function to apply to each element.
 */
template <typename T, typename Func>
void iter(T* array, size_t length, Func f)
{
    if (!array) { return; }
    for (size_t i = 0; i < length; ++i) { f(array[i]); }
}