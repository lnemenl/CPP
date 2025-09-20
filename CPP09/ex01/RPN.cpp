// RPN.cpp

#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <exception>
#include <unordered_set>

static const std::unordered_set<char> OPERATORS = {'+', '-', '*', '/'};

// static makes it so that it can only be used inside this .cpp file
static void performOperation(char op, std::stack<long long>& numbers)
{
	if (numbers.size() < 2)
	{
		throw std::runtime_error("Error");
	}

	long long right_num = numbers.top(); // Get
	numbers.pop(); // Remove
	long long left_num = numbers.top();
	numbers.pop();

	switch (op)
	{
		case '+':
			numbers.push(left_num + right_num);
			break;
		case '-':
			numbers.push(left_num - right_num);
			break;
		case '*':
			numbers.push(left_num * right_num);
			break;
		case '/':
			if (right_num == 0)
			{
				throw std::runtime_error("Error");
			}
			numbers.push(left_num / right_num);
			break;
	}
}


long long RPN::do_RPN(const std::string& expression)
{
	std::stack<long long> numbers;
	std::stringstream strstr(expression);
	std::string token;

	while (strstr >> token)
	{
		if (token.length() == 1 && OPERATORS.count(token[0]))
		{
			performOperation(token[0], numbers);
		}
		else if (token.length() == 1 && std::isdigit(token[0]))
		{
			// converting the character to an integer and pushing it
			numbers.push(token[0] - '0');
		}
		else
		{
			throw std::runtime_error("Error");
		}
	}
	// if there are more or fewer characters, the expression is not correct
	if (numbers.size() != 1)
	{
		throw std::runtime_error("Error");
	}
	return numbers.top();
}