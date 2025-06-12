/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:15:52 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/12 12:16:45 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "[Cat] Contstructor called";
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
	std::cout << "[Cat] copy constructor called" << obj.getType() << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
		Animal::operator=(obj);
	return *this;
}

Cat::~Cat()
{
	std::cout << "[Cat] destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MEOW sound" << std::endl;
}

