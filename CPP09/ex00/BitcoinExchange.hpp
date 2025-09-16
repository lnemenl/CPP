#include <string>
#include <map>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;

		void loadDatabase();
		void parseDatabaseLine(const std::string& line);
		void processInputFile(const std::string& filename);
		bool isValidValue(float value) const;
		bool isValidDate(const std::string& dateStr) const;
		
	public:
		BitcoinExchange();
		~BitcoinExchange() = default;
		BitcoinExchange(const BitcoinExchange&) = delete;
		BitcoinExchange& operator=(const BitcoinExchange&) = delete;
};