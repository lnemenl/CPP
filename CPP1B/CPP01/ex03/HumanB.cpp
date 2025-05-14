/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:13:05 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/14 15:27:32 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack()
{
    std::cout << this->name_ << " attacks with their " << this->weapon_->getType() << "\n";
}

HumanB::HumanB()
{

}

HumanB::~HumanB()
{
    
}

HumanB::HumanB(std::string name)
{
    name_ = name;
}


void HumanB::setWeapon(Weapon & new_weapon)
{
    this->weapon_ = &new_weapon;
}