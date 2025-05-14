/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:37:05 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/14 12:22:15 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie a("Ellis");
    a.announce();
    Zombie x = Zombie();
    x.announce();
    size_t N = 5;
    Zombie *b = zombieHorde(N, "Eclipse");
    for (size_t i = 0; i < N; i++)
    {
        if (b != nullptr)
            b[i].announce();
    }
    delete[] b;
}
