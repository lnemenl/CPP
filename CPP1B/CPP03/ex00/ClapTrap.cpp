/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:11:52 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/02 13:49:25 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "Constructor with name called" << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap& obj)
	: name(obj.name), hit_points(obj.hit_points), energy_points(obj.energy_points), attack_damage(obj.attack_damage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		hit_points = obj.hit_points;
		energy_points = obj.energy_points;
		attack_damage = obj.attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}


//Member functions

void ClapTrap::attack(const std::string& target)
{
	if (hit_points == 0 || energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " cannot attack. No hit points or energy points left." << std::endl;
		return ;
	}
	energy_points--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;	  
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " is already destroyed." << std::endl;
		return ;		
	}
	if (amount >= hit_points)
			hit_points = 0;
	else
		hit_points -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage." << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points == 0 || energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " cannot repair. No hit points or energy points left." << std::endl;
		return ;
	}
	energy_points--;
	hit_points += amount;
	std::cout << "ClapTrap " << name << " repairs itself, recovering " << amount << " hit points." << std::endl; 
}

