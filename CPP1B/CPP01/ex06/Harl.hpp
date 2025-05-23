/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:42:07 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/22 11:47:01 by rkhakimu         ###   ########.fr       */
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
