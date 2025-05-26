/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:23:12 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/22 16:45:28 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::ComplaintFunc

Harl::getComplaintFunc(std::string level)
{
	if (level == "DEBUG") return &Harl::debug;
	if (level == "INFO") return &Harl::info;
	if (level == "WARNING") return &Harl::warning;
	if (level == "ERROR") return &Harl::error;
	return nullptr;	
}

void Harl::complain(std::string level)
{
	ComplaintFunc func = getComplaintFunc(level);
	if (func)
	{
		(this->*func)();
	}
	else
	{
		std::cout << "[Harl] Invalid level: " << level << std::endl;
	}
}

void Harl::debug()
{
	std::cout	<< "[DEBUG] I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				<< "I really do!" << std::endl;
}

void Harl::info()
{
	std::cout	<< "[INFO] I cannot believe adding extra bacon costs more money. "
				<< "You didn't put enough bacon in my burger! "
				<< "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout	<< "[WARNING] I think I deserve to have some extra bacon for free. "
				<< "I've been coming for years whereas you started "
				<< "working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout	<< "[ERROR] This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}
