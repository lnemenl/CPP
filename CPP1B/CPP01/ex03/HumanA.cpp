/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:12:59 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/14 15:27:07 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << this->name_ << " attacks with their " << this->weapon_->getType() << "\n";
}

HumanA::HumanA(std::string name, Weapon & weapon)
{
    name_   = name;
    weapon_ = &weapon;
}

HumanA::HumanA()
{
    
}

HumanA::~HumanA()
{
    
}

