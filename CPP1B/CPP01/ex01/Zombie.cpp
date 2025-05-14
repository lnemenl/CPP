/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:16:58 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/14 12:01:01 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

void Zombie::announce() const
{
    std::cout << this->name_ << " BraiiiiiiinnnzzzZ..." << "\n";
}

Zombie::~Zombie()
{
    std::cout << this->name_ << " is destroyed\n";    
}


Zombie::Zombie(std::string name)
{
    name_ = name;
}

void Zombie::setName(std::string name)
{
    this->name_ = name;
}