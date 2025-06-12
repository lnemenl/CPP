/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:46:23 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/12 12:25:04 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "[Dog] Contstructor called" << std::endl;
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
	std::cout << "[Dog] copy constructor called" << obj.getType() << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this != &obj)
		Animal::operator=(obj);
	return *this;
}

Dog::~Dog()
{
	std::cout << "[Dog] destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "BARK sound" << std::endl;
}