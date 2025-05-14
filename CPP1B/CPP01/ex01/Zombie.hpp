/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:17:00 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/14 11:42:15 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <memory>
#include <iostream>

class Zombie
{
	public:
		Zombie(void);
		explicit Zombie(std::string name);
		~Zombie();
		void announce() const;
		void setName(std::string name);
	private:
		std::string name_;
};

Zombie *zombieHorde(int N, std::string name);