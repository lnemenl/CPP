/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:15:52 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/13 12:46:50 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain())
{
	type = "Cat";
	//std::cout << "[Cat] Contstructor called" <<std::endl;
}

Cat::Cat(const Cat& obj) : Animal(obj), brain(new Brain(*obj.brain))
{
	//std::cout << "[Cat] copy constructor called" << obj.getType() << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
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

Cat::~Cat()
{
	//std::cout << "[Cat] destructor called" << std::endl;
	delete(brain);
}

void Cat::makeSound() const
{
	std::cout << "[MEOW] sound" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}

const std::string Cat::getIdea(int index) const
{
	return brain->getIdea(index);
}

