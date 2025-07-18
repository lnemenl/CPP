#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <cctype>


void ScalarConverter::convert(std::string_view literal)
{
    const ScalarConverter::LiteralType type = detectType(literal);
    if (type == ScalarConverter::LiteralType::INVALID) return displayImpossible();
    if (type == ScalarConverter::LiteralType::PSEUDO) return displayPseudo(literal);

    errno = 0;

    if (type == ScalarConverter::LiteralType::CHAR)
    {
        char c = literal[0];
        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);
        return displayAll(c, i, f, d);
    }

    if (type == ScalarConverter::LiteralType::INT)
    {
        char* end = nullptr;
        long l = std::strtol(literal.data(), &end, 10);
        if (errno || *end != '\0' || l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
            return displayImpossible();
        int i = static_cast<int>(l);
        float f = static_cast<float>(i);
        double d = static_cast<double>(i);
        char c = static_cast<char>(i);
        return displayAll(c, i, f, d);
    }

    if (type == ScalarConverter::LiteralType::FLOAT)
    {
        std::string core = std::string(literal.substr(0, literal.size() - 1)); // remove 'f'
        char* end = nullptr;
        float f = std::strtof(core.c_str(), &end);
        if (errno || *end != '\0')
            return displayImpossible();
        int i = static_cast<int>(f);
        double d = static_cast<double>(f);
        char c = static_cast<char>(i);
        return displayAll(c, i, f, d);
    }

    if (type == ScalarConverter::LiteralType::DOUBLE)
    {
        char* end = nullptr;
        double d = std::strtod(std::string(literal).c_str(), &end);
        if (errno || *end != '\0')
            return displayImpossible();
        int i = static_cast<int>(d);
        float f = static_cast<float>(d);
        char c = static_cast<char>(i);
        return displayAll(c, i, f, d);
    }
}

void ScalarConverter::displayAll(char c, int i, float f, double d)
{
    displayChar(c, i, f, d);
    displayInt(i, f, d);
    displayFloat(f, d);
    displayDouble(d);
}

void ScalarConverter::displayImpossible()
{
    std::cout << "char: impossible\n"
              << "int: impossible\n"
              << "float: impossible\n"
              << "double: impossible\n";
}

void ScalarConverter::displayPseudo(std::string_view s)
{
    std::string base = std::string(s);
    if (s.ends_with('f')) base = base.substr(0, base.size() - 1);
    std::cout << "char: impossible\n"
              << "int: impossible\n"
              << "float: " << base << "f\n"
              << "double: " << base << "\n";
}

void ScalarConverter::displayChar(char c, int i, float f, double d)
{
    (void)f;
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || i < 0 || i > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(c))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << c << "'\n";
}

void ScalarConverter::displayInt(int i, float f, double d)
{
    (void)f;
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d))
        std::cout << "impossible\n";
    else
        std::cout << i << "\n";
}

void ScalarConverter::displayFloat(float f, double d)
{
    (void)d;
    std::cout << "float: ";
    if (std::isnan(f) || std::isinf(f))
        std::cout << "impossible\n";
    else
        std::cout << std::fixed << std::setprecision(1) << f << "f\n";
}

void ScalarConverter::displayDouble(double d)
{
    std::cout << "double: ";
    if (std::isnan(d) || std::isinf(d))
        std::cout << "impossible\n";
    else
        std::cout << std::fixed << std::setprecision(1) << d << "\n";
}

// Type detection
ScalarConverter::LiteralType ScalarConverter::detectType(std::string_view s)
{
    if (isPseudoLiteral(s)) return ScalarConverter::LiteralType::PSEUDO;
    if (isCharLiteral(s))   return ScalarConverter::LiteralType::CHAR;
    if (isIntLiteral(s))    return ScalarConverter::LiteralType::INT;
    if (isFloatLiteral(s))  return ScalarConverter::LiteralType::FLOAT;
    if (isDoubleLiteral(s)) return ScalarConverter::LiteralType::DOUBLE;
    return ScalarConverter::LiteralType::INVALID;
}

bool ScalarConverter::isCharLiteral(std::string_view s)
{
    return s.size() == 1 && !std::isdigit(s[0]) && std::isprint(s[0]);
}

bool ScalarConverter::isIntLiteral(std::string_view s)
{
    if (s.empty()) return false;
    size_t i = (s.front() == '-' || s.front() == '+') ? 1 : 0;
    if (i == s.size()) return false; // Checking whether it is only + or -
    for (; i < s.size(); ++i) // i is set above for a sign, so we check the real number if it is a digit.
        if (!std::isdigit(s[i])) return false;
    return true;
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
    size_t i = (s.front() == '-' || s.front() == '+') ? 1 : 0;
    if (i == s.size()) return false;
    for (; i < s.size(); ++i)
    {
        if (s[i] == '.')
        {
            if (dot) return false;
            dot = true;
        } else if (!std::isdigit(s[i])) return false;
    }
    return dot;
}

bool ScalarConverter::isPseudoLiteral(std::string_view s)
{
    return s == "nan" || s == "nanf" ||
           s == "+inf" || s == "-inf" ||
           s == "+inff" || s == "-inff";
}
