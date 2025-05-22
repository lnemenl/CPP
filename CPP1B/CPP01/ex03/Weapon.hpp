/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:13:16 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/22 16:34:02 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Weapon
{
    private:
        std::string type;

    public:
        Weapon(std::string type);
        const std::string& getType() const;
        void setType(std::string type);
};
