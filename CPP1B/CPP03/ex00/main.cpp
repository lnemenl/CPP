/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:12:01 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/02 13:59:07 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	//Testing default constructor
	ClapTrap a;
	//Testing constructor with name
	ClapTrap b("pirate");

	//Testing attack
	b.attack("Target1");

	//Testing takeDamage
	b.takeDamage(3);

	//Testing beRepaired
	b.beRepaired(5);

	//Testing energy depletion
	for (int i = 0; i < 11; ++i)
		b.attack("Target2");

	//Testing repairing with no energy
	b.beRepaired(2);

	//Testing taking fatal damage
	b.takeDamage(100);

	//Testing attacking and repairing with 0 hit points
	b.attack("Target3");
	b.beRepaired(10);

	//Testing copy constructor
	ClapTrap c(b);

	//Testing assignment operator
	a = b;

	//Testing actions on a new object
	a.attack("Target4");
	a.takeDamage(5);
	a.beRepaired(3);

	return 0;
}