/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:16:52 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/14 11:06:20 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    /* Zombie a =  */Zombie a("Ellis");
    a.announce();
    Zombie *b = newZombie("Andrey");
    b->announce();
    delete b;
    randomChump("Andrey Pavlovich");

    Zombie c = Zombie("");
    c.announce();
}