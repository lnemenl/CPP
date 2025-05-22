/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:16:52 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/22 13:35:29 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    std::cout << "creating zombie on heap" << std::endl;
    Zombie* zombie1 = newZombie("Kirill");
    zombie1->announce();
    delete zombie1;
    
    std::cout << "Creating zombie on stack" << std::endl;
    
    randomChump("Mifodii");
    
    return (0);
}

