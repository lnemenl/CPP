/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:13:54 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/14 12:20:33 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    if (N < 0)
    {
        std::cerr << "Change your mind \n";
        return (nullptr);
    }
    Zombie *zombies = new Zombie[N];
    for (size_t i = 0; i < (size_t)N; i++)
    {
        zombies[i].setName(name);
    }
    return (zombies);
}