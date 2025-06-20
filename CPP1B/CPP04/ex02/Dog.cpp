/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:46:23 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/14 15:19:29 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
	std::cout << "[Dog] Contstructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& obj) : Animal(obj), brain(new Brain(*obj.brain))
{
	std::cout << "[Dog] copy constructor called" << obj.getType() << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this != &obj)
	{
		Animal::operator=(obj);
		if (brain)
			delete(brain);
		brain = new Brain(*obj.brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "[Dog] destructor called" << std::endl;
	delete(brain);
}

void Dog::makeSound() const
{
	std::cout << "[BARK] sound" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return brain->getIdea(index);
}
