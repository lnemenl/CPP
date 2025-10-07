#pragma once

#include <string>
class RPN
{
	public:
		static long long do_RPN(const std::string& expression);

	private:
		RPN() = delete;
		RPN(const RPN&) = delete;
		RPN& operator=(const RPN&) = delete;
		~RPN() = delete;
};