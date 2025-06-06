/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:13:02 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/06 19:08:05 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const FragTrap& obj);
		DiamondTrap& operator=(const DiamondTrap& obj);
	   ~DiamondTrap() override;
	   void whoAmI();
	   using ScavTrap::attack;
};

#endif
