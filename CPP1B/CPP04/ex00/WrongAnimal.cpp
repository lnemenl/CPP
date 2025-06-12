/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:32:04 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/12 13:33:47 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	//std::cout << "[WrongAnimal] constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) : type(obj.type)
{
	//std::cout << "[WrongAnimal] copy constructor called" << obj.type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	if (this != &obj)
		type = obj.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	//std::cout << "[WrongAnimal] destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal] sound" << std::endl;
}


const std::string& WrongAnimal::getType() const
{
	return (type);
}