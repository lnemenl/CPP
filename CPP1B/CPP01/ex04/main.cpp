/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:45:02 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/19 09:16:49 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string &text, const std::string &s1, const std::string &s2)
{
	std::string result;
	size_t match_pos = 0;
	size_t last_match_pos = 0;
	
	while ((match_pos = text.find(s1, last_match_pos)) != std::string::npos)
	{
		//Copying the text before the match
		result += text.substr(last_match_pos, match_pos - last_match_pos);
		//Adding replacement
		result += s2;
		last_match_pos = match_pos + s1.length();
	}
	//Copying remaining text
	result = text.substr(last_match_pos);
	return (result);
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return (1); 
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3]
}