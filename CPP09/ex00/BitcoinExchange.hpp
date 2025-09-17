#include <string>
#include <map>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;

		void loadDatabase();
		void parseDatabaseLine(const std::string& line);
		bool isValidValue(float value) const;
		bool isValidDate(const std::string& dateStr) const;
		float findExchangeRate(const std::string& date) const;
		bool reportError(const std::string& message, const std::string& line) const;
		void processLine(const std::string& line);
		bool parseInputLine(const std::string& line, std::string& date, float& value);


	public:
		BitcoinExchange();
		~BitcoinExchange() = default;
		BitcoinExchange(const BitcoinExchange&) = delete;
		BitcoinExchange& operator=(const BitcoinExchange&) = delete;
		void processInputFile(const std::string& filename);
};
