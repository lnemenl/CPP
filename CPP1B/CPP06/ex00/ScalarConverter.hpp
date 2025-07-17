/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:03:05 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/07/17 13:23:36 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <string_view>
#include <iostream>
#include <limits>
#include <iomanip>


class ScalarConverter
{
	private:
		ScalarConverter() 									= delete;
		ScalarConverter(const ScalarConverter&)				= delete;
		ScalarConverter& operator=(const ScalarConverter&)	= delete;
		~ScalarConverter()									= delete;
		
		enum class LiteralType
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PSEUDO,
			INVALID
		};
		
		struct ConversionResult
		{
			char			charValue{0};
			int				intValue{0};
			float			floatValue{0.0f};
			double			doubleValue{0.0};
			bool			isCharValid{false};
			bool			isIntValid{false};
			bool			isPseudo{false};
			std::string		pseudoLiteral;
		};
		
		// Type detection
		static bool			isCharLiteral(std::string_view literal);
		static bool			isIntLiteral(std::string_view literal);
		static bool			isFloatLiteral(std::string_view literal);
		static bool			isDoubleLiteral(std::string_view literal);
		static bool			isPseudoLiteral(std::string_view literal);
		static LiteralType	detectType(std::string_view literal);

		// Converting to actual type
		static void			toChar(std::string_view literal, ConversionResult& result);
    	static void			toInt(std::string_view literal, ConversionResult& result);
    	static void			toFloat(std::string_view literal, ConversionResult& result);
    	static void			toDouble(std::string_view literal, ConversionResult& result);
    	static void			toPseudo(std::string_view literal, ConversionResult& result);

		// Convert to other types
		static void			toCharFromInt(const ConversionResult& src, ConversionResult& dest);
    	static void			toCharFromFloat(const ConversionResult& src, ConversionResult& dest);
    	static void			toCharFromDouble(const ConversionResult& src, ConversionResult& dest);
    	static void			toIntFromChar(const ConversionResult& src, ConversionResult& dest);
    	static void			toIntFromFloat(const ConversionResult& src, ConversionResult& dest);
    	static void			toIntFromDouble(const ConversionResult& src, ConversionResult& dest);
    	static void			toFloatFromChar(const ConversionResult& src, ConversionResult& dest);
    	static void			toFloatFromInt(const ConversionResult& src, ConversionResult& dest);
    	static void			toFloatFromDouble(const ConversionResult& src, ConversionResult& dest);
    	static void			toDoubleFromChar(const ConversionResult& src, ConversionResult& dest);
    	static void			toDoubleFromInt(const ConversionResult& src, ConversionResult& dest);
    	static void			toDoubleFromFloat(const ConversionResult& src, ConversionResult& dest);
		
		// Displaying the results
		static void			displayChar(const ConversionResult& result);
    	static void			displayInt(const ConversionResult& result);
    	static void			displayFloat(const ConversionResult& result);
    	static void			displayDouble(const ConversionResult& result);

	public:
		static void			convert(const std::string& literal);
};

// A static method in a class is a function that:
// Belongs to the class itself, not to any specific object.
// Can be called without creating an object of the class.
// Cannot access non-static members (variables or methods) of the class directly,
// because it does not have a this pointer
