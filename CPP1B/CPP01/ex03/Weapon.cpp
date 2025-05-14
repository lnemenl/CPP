/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:13:13 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/14 15:32:48 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string & Weapon::getType() const
{
    return (type_);
}


void Weapon::setType(std::string type)
{
    type_ = type;
}


Weapon::Weapon(std::string type)
{
    this->setType(type);
}


Weapon::~Weapon()
{
    
}


Weapon::Weapon()
{
    
}