#include <string>
#include <map>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;

		void loadDatabase();
		void parseDatabaseLine(const std::string& line);

		
	public:
		BitcoinExchange();
		~BitcoinExchange() = default;
		BitcoinExchange(const BitcoinExchange&) = delete;
		BitcoinExchange& operator=(const BitcoinExchange&) = delete;
};