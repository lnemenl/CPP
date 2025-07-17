/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:03:17 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/07/17 13:51:47 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <charconv>
#include <cmath>
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


void ScalarConverter::toFloat(std::string_view literal, ConversionResult& result)
{
	if(literal.back() == 'f') literal.remove_suffix(1);
	float value;
	auto[ptr, ec] = std::from_chars(literal.data(), literal.data() + literal.size(), value);
	if (ec == std::errc() && ptr == literal.data() + literal.size())
	{
		result.floatValue = value;
		result.isIntValid = static_cast<double>(value) >= 	static_cast<double>(std::numeric_limits<int>::min()) &&
							static_cast<double>(value) <= 	static_cast<double>(std::numeric_limits<int>::max()) &&
							!std::isnan(value) && !std::isinf(value);
	}
}

void ScalarConverter::toDouble(std::string_view literal, ConversionResult& result)
{
	double value;
	auto[ptr, ec] = std::from_chars(literal.data(), literal.data() + literal.size(), value);
	if (ec == std::errc() && ptr == literal.data() + literal.size())
	{
		result.doubleValue = value;
		result.isIntValid = value >= std::numeric_limits<int>::min() &&
							value <= std::numeric_limits<int>::max() &&
							!std::isnan(value) && !std::isinf(value);	
	}
}

void ScalarConverter::toPseudo(std::string_view literal, ConversionResult& result)
{
	result.isPseudo = true;
	result.pseudoLiteral = std::string(literal);
	if (literal == "-inf" || literal == "-inff")
		result.doubleValue = -std::numeric_limits<double>::infinity();
	else if (literal == "+inf" || literal == "+inff")
		result.doubleValue = std::numeric_limits<double>::infinity();
	else
		result.doubleValue = std::numeric_limits<double>::quiet_NaN();
}

void ScalarConverter::toCharFromInt(const ConversionResult& src, ConversionResult& dest)
{
	dest.charValue = static_cast<char>(src.intValue);
	dest.isCharValid = src.isIntValid && src.intValue >= 0 && src.intValue <= 127 && std::isprint(src.intValue);
}

void ScalarConverter::toCharFromFloat(const ConversionResult& src, ConversionResult& dest)
{
	dest.charValue = static_cast<char>(src.floatValue);
	dest.isCharValid = src.isIntValid && src.floatValue >= 0 && src.floatValue <= 127 && std::isprint(static_cast<int>(src.floatValue));
}

void ScalarConverter::toCharFromDouble(const ConversionResult& src, ConversionResult& dest)
{
	dest.charValue = static_cast<char>(src.doubleValue);
	dest.isCharValid = src.isIntValid && src.doubleValue >= 0 && src.doubleValue <= 127 && std::isprint(static_cast<int>(src.doubleValue));
}

void ScalarConverter::toIntFromChar(const ConversionResult& src, ConversionResult& dest)
{
	dest.intValue = static_cast<int>(src.charValue);
	dest.isIntValid = src.isCharValid;
}

void ScalarConverter::toIntFromFloat(const ConversionResult& src, ConversionResult& dest)
{
	dest.intValue = static_cast<int>(src.floatValue);
	dest.isIntValid = src.isIntValid;
}

void ScalarConverter::toIntFromDouble(const ConversionResult& src, ConversionResult& dest)
{
	dest.intValue = static_cast<int>(src.doubleValue);
	dest.isIntValid = src.isIntValid;
}

void ScalarConverter::toFloatFromChar(const ConversionResult& src, ConversionResult& dest)
{
	dest.floatValue = static_cast<float>(src.charValue);
}

void ScalarConverter::toFloatFromInt(const ConversionResult& src, ConversionResult& dest)
{
	dest.floatValue = static_cast<float>(src.intValue);
}

void ScalarConverter::toFloatFromDouble(const ConversionResult& src, ConversionResult& dest)
{
	dest.floatValue = static_cast<float>(src.doubleValue);
}

void ScalarConverter::toDoubleFromChar(const ConversionResult& src, ConversionResult& dest)
{
    dest.doubleValue = static_cast<double>(src.charValue);
}

void ScalarConverter::toDoubleFromInt(const ConversionResult& src, ConversionResult& dest)
{
    dest.doubleValue = static_cast<double>(src.intValue);
}

void ScalarConverter::toDoubleFromFloat(const ConversionResult& src, ConversionResult& dest)
{
    dest.doubleValue = static_cast<double>(src.floatValue);
}

void ScalarConverter::displayChar(const ConversionResult& result)
{
	std::cout << "char: ";
	if (result.isPseudo || !result.isCharValid)
	{
		std::cout << "impossible" << std::endl;
	}
	else if (!std::isprint(result.charValue))
	{
		std::cout << "Non displayable" << std::endl;
	}
	else
	{
		std::cout << "'" << result.charValue << "'" << std::endl;
	}
}

void ScalarConverter::displayInt(const ConversionResult& result)
{
	std::cout << "int: ";
	if (result.isPseudo || !result.isIntValid)
	{
		std::cout << "impossible " << std::endl;
	}
	else
	{
		std::cout << result.intValue << std::endl;
	}
}

void ScalarConverter::displayFloat(const ConversionResult& result)
{
	std::cout << "float: ";
	if (result.isPseudo)
	{
		std::string out = result.pseudoLiteral;
		if (out == "-inf" || out == "+inf" || out == "nan") out += "f";
		std::cout << out << std::endl;
	}
	else if (std::isnan(result.doubleValue) || std::isinf(result.doubleValue))
	{
		std::cout << (result.doubleValue < 0 ? "-inf" : "+inf") << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1) << result.floatValue << "f" << std::endl;
	}
}

void ScalarConverter::displayDouble(const ConversionResult& result)
{
	std::cout << "double: ";
	if (result.isPseudo)
	{
		std::string out = result.pseudoLiteral;
		if (out == "-inff" || out == "+inff" || out == "nanf") out = out.substr(0, out.length() - 1);
		std::cout << out << std::endl;
	}
	else if (std::isnan(result.doubleValue) || std::isinf(result.doubleValue))
	{
		std::cout << (result.doubleValue < 0 ? "-inf" : "+inf") << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1) << result.doubleValue << std::endl;
	}
}

void ScalarConverter::convert(const std::string& literal)
{
	if (literal.empty())
	{
		std::cout << "Error: empty input" << std::endl;
		return;
	}
	ConversionResult result;
	LiteralType type = detectType(literal);
	switch (type)
	{
		case LiteralType::CHAR:
		{
			toChar(literal, result);
			toIntFromChar(result, result);
			toFloatFromChar(result, result);
			toDoubleFromChar(result, result);
			break;
		}
		case LiteralType::INT:
		{
			toInt(literal, result);
			if (result.isIntValid)
			{
				toCharFromInt(result, result);
				toFloatFromInt(result, result);
				toDoubleFromInt(result, result);
			}
			break;
		}
		case LiteralType::FLOAT:
		{
			toFloat(literal, result);
			if(result.isIntValid)
			{
				toCharFromFloat(result, result);
				toIntFromFloat(result, result);
				toDoubleFromFloat(result, result);
			}
			break;
		}
		case LiteralType::DOUBLE:
		{
			toDouble(literal, result);
			if(result.isIntValid)
			{
				toCharFromDouble(result, result);
				toIntFromDouble(result, result);
				toFloatFromDouble(result, result);
			}
			break;
		}
		case LiteralType::PSEUDO:
		{
			toPseudo(literal, result);
			break;
		}
		case LiteralType::INVALID:
		{
			break;
		}
	}
	displayChar(result);
	displayInt(result);
	displayFloat(result);
	displayDouble(result);
}