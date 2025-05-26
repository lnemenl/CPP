/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:16:52 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/26 14:08:15 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    Zombie* zombie1 = nullptr;
    Zombie* zombie2 = nullptr;
    try 
    {
        std::cout << "creating zombie on heap" << std::endl;
        zombie1 = newZombie("Kirill");
        zombie1->announce();
        zombie2 = newZombie("Pekka");
        zombie2->announce();
        delete zombie1;
        delete zombie2;
        std::cout << "Creating zombie on stack" << std::endl;
    }
    
    catch (const std::bad_alloc& e)
    {
        delete zombie1;
        std::cerr << e.what() << std::endl;
        return (1);
    }
    randomChump("Mifodii");
    return (0);
}

/*  If an exception is thrown before the pointer is assigned
    a valid address, deleting a nullptr is safe and does nothing.
    Deleting an uninitialized (garbage) pointer 
    is undefined behavior and can crash your program.*/