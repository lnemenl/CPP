/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:13:07 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/14 15:26:15 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB();
        ~HumanB();
        HumanB(std::string name);
        void setWeapon(Weapon & new_weapon);
        void attack();
    private:
        std::string name_;
        Weapon *weapon_;
};