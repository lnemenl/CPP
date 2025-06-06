/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:12:08 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/06 16:02:58 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "\n=== 🔨 DEFAULT & NAMED CONSTRUCTORS ===" << std::endl;
	ClapTrap a;
	ClapTrap b("Bob");

	std::cout << "\n=== COPY CONSTRUCTOR ===" << std::endl;
	ClapTrap original("OG");
	ClapTrap copy(original);  // copy constructor call

	std::cout << "\n=== COPY ASSIGNMENT ===" << std::endl;
	ClapTrap source("Source");
	ClapTrap target("Target");
	target = source;          // assignment operator call

	std::cout << "\n=== SCAVTRAP TESTS ===" << std::endl;
	ScavTrap scav1("Guardian");
	ScavTrap scav2(scav1);    // copy constructor
	ScavTrap scav3;
	scav3 = scav1;            // assignment operator

	std::cout << "\n=== GUARD MODE ===" << std::endl;
	scav1.guardGate();

	std::cout << "\n=== DESTRUCTOR ORDER CHECK (SCOPED BLOCK) ===" << std::endl;
	{
		ScavTrap scoped("Scoped");
	}
	std::cout << "Exited scope.\n";

	std::cout << "\n=== ✅ END OF MAIN ===" << std::endl;
	return 0;
}

