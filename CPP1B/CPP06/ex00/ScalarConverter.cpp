/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:03:17 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/07/14 22:24:42 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
#include <cctype>
#include <charconv>
//c_cpp_properties.json


bool    ScalarConverter::isCharLiteral(std::string_view literal)
{
	return literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'' && std::isprint(literal[1]);
}

bool    ScalarConverter::isPseudoLiteral(std::string_view literal)
{
	return	literal == "-inf" || literal == "+inf" || literal == "nan" ||
			literal == "-inff" || literal == "+inff" || literal == "nanf";
}

bool	ScalarConverter::isIntLiteral(std::string_view literal)
{
	if (literal.empty()) return false;
	size_t start = (literal[0] == '+' || literal[0] == '-') ? 1 : 0;
	if (start == literal.size()) return false;
	
	for (size_t i = start; i < literal.size(); ++i)
	{
		if (!std::isdigit(literal[i])) return false;
	}
	return true;
}

bool ScalarConverter::isFloatLiteral(std::string_view literal)
{
	if (literal.empty() || literal.back() != 'f') return false;
	std::string_view num = literal.substr(0, literal.size() - 1);
	if (num.empty()) return false;
	size_t start = (num[0] == '+' || num[0] == '-') ? 1 : 0;
	bool hasDot = false;
	for (size_t i = start; i < num.size(); ++i)
	{
		if (num[i] == '.')
		{
			if (hasDot) return false;
			hasDot = true;
		}
		else if (!std::isdigit(num[i]))
		{
			return false;
		}
	}
	return hasDot;
}

bool ScalarConverter::isDoubleLiteral(std::string_view literal)
{
    if (literal.empty()) return false;
    size_t start = (literal[0] == '+' || literal[0] == '-') ? 1 : 0;
    if (start == literal.size()) return false;
    bool hasDot = false;
    for (size_t i = start; i < literal.size(); ++i)
	{
        if (literal[i] == '.')
		{
            if (hasDot) return false;
            hasDot = true;
        }
		else if (!std::isdigit(literal[i]))
		{
            return false;
        }
    }
    return hasDot;
}

ScalarConverter::LiteralType ScalarConverter::detectType(std::string_view literal)
{
	if (literal.empty())			return LiteralType::INVALID;
	if (isPseudoLiteral(literal))	return LiteralType::PSEUDO;
	if (isCharLiteral(literal))		return LiteralType::CHAR;
	if (isFloatLiteral(literal))	return LiteralType::FLOAT;
	if (isDoubleLiteral(literal))	return LiteralType::DOUBLE;
	if (isIntLiteral(literal))		return LiteralType::INT;
									return LiteralType::INVALID;
}

void	ScalarConverter::toChar(std::string_view literal, ConversionResult& result)
{
	result.charValue = literal[1];
	result.isCharValid = std::isprint(result.charValue);
}

void	ScalarConverter::toInt(std::string_view literal, ConversionResult& result)
{
    int value;
    auto [ptr, ec] = std::from_chars(literal.data(), literal.data() + literal.size(), value);
    if (ec == std::errc() && ptr == literal.data() + literal.size())
	{
        result.intValue = value;
        result.isIntValid = true;
	}
}


