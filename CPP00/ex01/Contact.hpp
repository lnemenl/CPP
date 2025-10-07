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
		bool checkField(std::string& input);
};
