#include <string>
#include <map>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> mapa;
	public:
		BitcoinExchange() = default;
		~BitcoinExchange() = default;
		BitcoinExchange(const BitcoinExchange&) = delete;
		BitcoinExchange& operator=(const BitcoinExchange&) = delete;

		std::map<std::string, float>& getMapa()
		{
			return mapa;
		}

		const std::map<std::string, float>& getMapa() const
		{
			return mapa;
		}

};