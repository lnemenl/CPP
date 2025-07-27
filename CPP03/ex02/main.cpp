/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:12:47 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/06 16:02:28 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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

	std::cout << "\n=== FragTrap TESTS ===" << std::endl;
	FragTrap frag1("Guardian");
	FragTrap frag2(frag1);    // copy constructor
	FragTrap frag3;
	frag3 = frag1;            // assignment operator

	std::cout << "\n=== High Five ===" << std::endl;
	frag1.highFiveGuys();

	std::cout << "\n=== DESTRUCTOR ORDER CHECK (SCOPED BLOCK) ===" << std::endl;
	{
		FragTrap scoped("Scoped");
	}
	std::cout << "Exited scope.\n";

	std::cout << "\n=== ✅ END OF MAIN ===" << std::endl;
	return 0;
}