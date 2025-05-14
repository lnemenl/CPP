/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:42:37 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/14 14:09:39 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string s = "HI THIS IS BRAIN";
    std::string *stringPTR = &s;
    std::string &stringREF = s;

    std::cout << &s << "\n";
    std::cout << &stringPTR << "\n";
    std::cout << &stringREF << "\n";
    
    std::cout << s << "\n";
    std::cout << stringPTR << "\n";
    std::cout << stringREF << "\n";
}
