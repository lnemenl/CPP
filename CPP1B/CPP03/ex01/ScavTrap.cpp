/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:12:31 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/04 21:25:25 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()  name(), hit_points(100), energy_points(50), attack_damage(20)
{
    std::cout << "Constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : name(name), hit_points(100), energy_points(50), attack_damage(20)
{
    std::cout << "Constructor ScavTrap with name called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) :
    name(obj.name), hit_points(obj.hit_points), energy_points(obj.energy_points), attack_damage(obj.attack_damage)
{
    std::cout << "Copy Constructor ScavTrap called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    std::cout << "Copy assignment operator ScavTrap called" << std::endl;
    if (this != &obj)
    {
        name = obj.name;
        hit_points = obj.hit_points;
        energy_points = obj.energy_points;
        attack_damage = obj.attack_damage;
    }
    return *this;
}

ScavTrap:: ~ScavTrap()
{
    std::cout << "Destructor ScavTrap called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode"
}
