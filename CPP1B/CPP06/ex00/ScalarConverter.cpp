#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
void ScalarConverter::convert(std::string_view literal)
{
    std::string trimmed(literal);
    trimmed.erase(0, trimmed.find_first_not_of(" \t"));
    trimmed.erase(trimmed.find_last_not_of(" \t") + 1);

    LiteralType type = detectType(trimmed);
    if (type == LiteralType::INVALID)
        return displayImpossible();

    try
    {
        if (type == LiteralType::CHAR)
        {
            char c = trimmed[0];
            return displayAll(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
        }

        if (type == LiteralType::INT)
        {
            int i = std::stoi(trimmed);
            return displayAll(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
        }

        if (type == LiteralType::FLOAT)
        {
            float f = std::stof(trimmed);
            return displayAll(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
        }

        if (type == LiteralType::DOUBLE || type == LiteralType::PSEUDO)
        {
            try
            {
                double d = std::stod(trimmed);
                float f = static_cast<float>(d);

                // If double is not inf, but float conversion results in inf or nan, assume overflow
                if (!std::isnan(d) && ((std::isinf(f) && !std::isinf(d)) || std::isnan(f)))
                    f = (d > 0) ? std::numeric_limits<float>::infinity() : -std::numeric_limits<float>::infinity();

                return displayAll(static_cast<char>(d), static_cast<int>(d), f, d);
            }
            catch (const std::out_of_range&)
            {
                // Handle overflow: print +inf/-inf for float and double
                bool negative = (!trimmed.empty() && trimmed[0] == '-');
                std::cout << "char: impossible\n"
                          << "int: impossible\n"
                          << "float: " << (negative ? "-inff" : "+inff") << "\n"
                          << "double: " << (negative ? "-inf" : "+inf") << "\n";
                return;
            }
        }
    }
    catch (...)
    {
        return displayImpossible();
    }
}


void ScalarConverter::displayAll(char c, int i, float f, double d)
{
    displayChar(c, d);
    displayInt(i, d);
    displayFloat(f);
    displayDouble(d);
}

void ScalarConverter::displayImpossible()
{
    std::cout << "char: impossible\n"
              << "int: impossible\n"
              << "float: impossible\n"
              << "double: impossible\n";
}

void ScalarConverter::displayChar(char c, double d)
{
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) ||
        d > std::numeric_limits<char>::max() ||
        d < std::numeric_limits<char>::min())
        std::cout << "impossible\n";
    else if (!std::isprint(c))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << c << "'\n";
}

void ScalarConverter::displayInt(int i, double d)
{
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) ||
        d > std::numeric_limits<int>::max() ||
        d < std::numeric_limits<int>::min())
        std::cout << "impossible\n";
    else
        std::cout << i << "\n";
}

void ScalarConverter::displayFloat(float f)
{
    std::cout << "float: ";
    if (std::isnan(f))
        std::cout << "nanf\n";
    else if (std::isinf(f))
        std::cout << (f > 0 ? "+inff" : "-inff") << "\n";
    else
        std::cout << std::fixed << std::setprecision(1) << f << "f\n";
}

void ScalarConverter::displayDouble(double d)
{
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan\n";
    else if (std::isinf(d))
        std::cout << (d > 0 ? "+inf" : "-inf") << "\n";
    else
        std::cout << std::fixed << std::setprecision(1) << d << "\n";
}

ScalarConverter::LiteralType ScalarConverter::detectType(std::string_view s)
{
    if (isPseudoLiteral(s)) return LiteralType::PSEUDO;
    if (isCharLiteral(s))   return LiteralType::CHAR;
    if (isIntLiteral(s))    return LiteralType::INT;
    if (isFloatLiteral(s))  return LiteralType::FLOAT;
    if (isDoubleLiteral(s)) return LiteralType::DOUBLE;
    return LiteralType::INVALID;
}

bool ScalarConverter::isCharLiteral(std::string_view s)
{
    return s.size() == 1 && !std::isdigit(s[0]) && std::isprint(s[0]);
}

bool ScalarConverter::isIntLiteral(std::string_view s)
{
    if (s.empty()) return false;
    try
    {
        size_t pos; // the position in the string where the conversion stopped.
        long long num = std::stoll(std::string(s), &pos);
        if (pos != s.size()) return false; //if 123abc, pos = 3 and size = 6 -> false
        return num >= std::numeric_limits<int>::min() &&
               num <= std::numeric_limits<int>::max();
    }
    catch (...)
    {
        return false;
    }
}

bool ScalarConverter::isFloatLiteral(std::string_view s)
{
    if (!s.ends_with('f') || s.size() < 2) return false;
    return isDoubleLiteral(s.substr(0, s.size() - 1));
}

bool ScalarConverter::isDoubleLiteral(std::string_view s)
{
    if (s.empty()) return false;
    bool dot = false;
    bool hasDigit = false;
    size_t i = (s.front() == '-' || s.front() == '+') ? 1 : 0;
    if (i == s.size()) return false;
    for (; i < s.size(); ++i)
    {
        if (s[i] == '.')
        {
            if (dot) return false;
            dot = true;
        }
        else if (std::isdigit(s[i]))
            hasDigit = true;
        else
            return false;
    }
    return hasDigit;
}

bool ScalarConverter::isPseudoLiteral(std::string_view s)
{
    return s == "nan" || s == "nanf" ||
           s == "+inf" || s == "-inf" ||
           s == "+inff" || s == "-inff";
}



/*

#!/bin/bash
inputs=(
    "42" "97" "0" "127" "128"
    "nan" "+inf" "-inf" "nanf" "+inff" "-inff"
    "340000000000000000000000000000"
    "-340000000000000000000000000000"
    "2147483648"
    "3.14f" "0.0f"
    "2.71828"
    "hello" "123abc" ""
    "a" "%" "Z"
)

for input in "${inputs[@]}"; do
    echo "Input: '$input'"
    ./ex00 "$input"
    echo "-------------------------"
done

*/