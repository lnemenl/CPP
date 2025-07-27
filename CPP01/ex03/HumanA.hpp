/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:13:02 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/27 16:16:12 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        /*reference, as HumanA is always armed*/
        Weapon& weapon;

    public:
        HumanA(std::string name, Weapon& weapon);
        void attack() const;
};