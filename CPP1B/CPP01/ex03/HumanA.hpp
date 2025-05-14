/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:13:02 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/14 15:26:07 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA();
        ~HumanA();
        HumanA(std::string name, Weapon & weapon);
        void attack();
    private:
        std::string name_;
        Weapon *weapon_;
};