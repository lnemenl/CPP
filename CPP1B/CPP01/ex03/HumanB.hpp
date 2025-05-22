/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:13:07 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/22 16:28:55 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		/*pointer, as HumanB may be unarmed*/
		Weapon* weapon;

	public:
		HumanB(std::string name);
		void setWeapon(Weapon& weapon);
		void attack() const;
};