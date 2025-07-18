#pragma once
#include <string>
#include <string_view>

class ScalarConverter
{
	public:
		static void convert(std::string_view literal);

	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter&) = delete;
		ScalarConverter& operator=(const ScalarConverter&) = delete;
		~ScalarConverter() = delete;

		enum class LiteralType
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PSEUDO,
			INVALID
		};

		static LiteralType detectType(std::string_view literal);
		static bool isCharLiteral(std::string_view s);
		static bool isIntLiteral(std::string_view s);
		static bool isFloatLiteral(std::string_view s);
		static bool isDoubleLiteral(std::string_view s);
		static bool isPseudoLiteral(std::string_view s);

		static void displayAll(char c, int i, float f, double d);
		static void displayImpossible();
		static void displayPseudo(std::string_view s);

		static void displayChar(char c, int i, float f, double d);
		static void displayInt(int i, float f, double d);
		static void displayFloat(float f, double d);
		static void displayDouble(double d);
};
