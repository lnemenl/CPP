/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:45:02 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/16 16:21:42 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string replaceAll(const std::string& text, const std::string& s1, const std::string& s2) {
    std::string result;
    size_t lastPos = 0;
    size_t pos = 0;
    // Find each occurrence of s1
    while ((pos = text.find(s1, lastPos)) != std::string::npos) {
        std::cout << "pos: " << pos << " lastPos: " << lastPos << std::endl;
        // Copy text before the match
        result += text.substr(lastPos, pos - lastPos);
        // Add replacement
        result += s2;
        lastPos = pos + s1.length();
    }
    std::cout << "pos: " << pos << " lastPos: " << lastPos << std::endl;
    // Copy remaining text
    result += text.substr(lastPos);
    return result;
}

int main(int ac, char *av[]) {
    if (ac != 4) return 1;
    std::cout << replaceAll("add some text some fun", av[2], av[3]) << std::endl;
    return 0;
}