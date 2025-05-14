/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:13:16 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/14 15:32:53 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Weapon
{
    private:
        std::string type_;
    public:
        Weapon();    
        Weapon(std::string type);
        ~Weapon();
        const std::string & getType() const;
        void setType(std::string type);
};
