/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:13:54 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/22 15:54:02 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
        std::cerr << "Change your mind \n";
        return (nullptr);
    }
    Zombie* horde = new Zombie[N];
    for (size_t i = 0; i < (size_t)N; ++i)
    {
        horde[i].setName(name);
    }
    return (horde);
}
