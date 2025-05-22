/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:42:22 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/22 12:02:06 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

enum LogLevel
{
	DEBUG = 0,
	INFO = 1,
	WARNING = 2,
	ERROR = 3,
	INVALID = -1
};

LogLevel getLogLevel(const std::string& level)
{
	if (level == "DEBUG")	return (DEBUG);
	if (level == "INFO")	return (INFO);
	if (level == "WARNING")	return (WARNING);
	if (level == "ERROR")	return (ERROR);
	return (INVALID);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./harlfilter <level>" << std::endl;
		return (1);
	}
	
	Harl harl;
	std::string level = av[1];
	LogLevel logLevel = getLogLevel(level);

	switch (logLevel)
	{
	case DEBUG:
		harl.complain("DEBUG");
	case INFO:
		harl.complain("INFO");
	case WARNING:
		harl.complain("WARNING");
	case ERROR:
		harl.complain("ERROR");
		break;
	default:
		std::cout << "[Harl] invalid level: " << level << std::endl;
	}
	return (0);
}
