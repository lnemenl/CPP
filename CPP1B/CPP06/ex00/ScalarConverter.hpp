/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:03:05 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/26 17:33:09 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <limits>
#include <cmath>

class ScalarConverter
{
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter&) = delete;
		ScalarConverter& operator=(const ScalarConverter&) = delete;
		~ScalarConverter() = default;
		
		static void convert(const std::string& input);
};

// A static method in a class is a function that:
// Belongs to the class itself, not to any specific object.
// Can be called without creating an object of the class.
// Cannot access non-static members (variables or methods) of the class directly,
// because it does not have a this pointer
