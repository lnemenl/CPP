/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:09:49 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/15 11:31:42 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#define MAX_CONTACTS 8

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	
	public:
		void setContact();
		void displaySummary(int index) const;
		void displayFull() const;
		bool isEmpty() const;
	
	private:
		std::string formatField(const std::string &field) const;
		bool isNumeric(const std::string &str) const;
};
