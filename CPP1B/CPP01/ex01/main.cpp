/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:37:05 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/22 14:13:00 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::cout << "Creating a horde of 5 zombies" << std::endl;

    size_t N = 5;
    Zombie* horde = zombieHorde(N, "HordeZombie");

    if (!horde)
    {
        std::cout << "Failed to create zombie horde" << std::endl;
        return (1);
    }
    
    for (size_t i = 0; i < N; ++i)
    {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }

    std::cout << "Destroying the horde" << std::endl;
    delete[] horde;

    std::cout << "Testing with N = 0" << std::endl;
    horde = zombieHorde(0, "Invalid");
    if (!horde)
    {
        std::cout << "nullptr for N <= 0 correctly returned" << std::endl;
        return (1);
    }
    return (1);
}
