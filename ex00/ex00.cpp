/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:21:15 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/04/28 16:39:30 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


char    my_toupper(char ch)
{
    std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
}
int main()
{
    char ch{};
    std::cin >> ch;
    
}