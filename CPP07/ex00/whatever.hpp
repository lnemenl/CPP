#pragma once

/**
 * @brief Swaps the values of two variables of the same type.
 * @details This function takes two references and swaps their contents using a
 * temporary variable.
 * @tparam T The type of the variables.
 * @param a Reference to the first variable.
 * @param b Reference to the second variable.
 */
template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

/**
 * @brief Returns a const reference to the smaller of two values.
 * @details Compares two values using the '<' operator.
 * If the values are equal, it returns the second argument.
 * @tparam T The type of the values, must support the '<' operator.
 * @param a Const reference to the first value.
 * @param b Const reference to the second value.
 * @return A const reference to the smaller value.
 */
template <typename T>
const T& min(const T& a, const T& b)
{
	return (a < b) ? a : b;
}

/**
 * @brief Returns a const reference to the larger of two values.
 * @details Compares two values using the '>' operator.
 * If the values are equal, it returns the second argument.
 * @tparam T The type of the values, must support the '>' operator.
 * @param a Const reference to the first value.
 * @param b Const reference to the second value.
 * @return A const reference to the larger value.
 */
template <typename T>
const T& max(const T& a, const T& b)
{
	return (a > b) ? a : b;
}