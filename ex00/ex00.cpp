/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:21:15 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/04/28 17:25:45 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int ac, char **av)
{    
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }

    for (int i = 1; i < ac; i++)
    {
        for (int j = 0; i < av[i][j]; j++)
        {
            std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(av[i][j])));
        }
    }
    std::cout << "\n" << std::flush;
    return (0);
}