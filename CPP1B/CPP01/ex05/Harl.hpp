/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:23:16 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/19 14:10:15 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Harl
{
	public:
		void complain(std::string level);
		
	private:
		void debug();
		void info();
		void warning();
		void error();
		typedef void(Harl::*ComplaintFunc)();
		ComplaintFunc getComplaintFunc(std::string level);
};


