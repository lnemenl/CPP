/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:40:24 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/04 14:00:27 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	int64_t result = static_cast<int64_t>(num) << fract_bits;
	if ((int)result != result)
	{
		std::cerr << "Overflow occured" << std::endl;
		throw std::out_of_range("overflow occured");
	}
	else
	{
		std::cout << "Int constructor called" << std::endl;
		_value = static_cast<int>(result);
	}
}

Fixed::Fixed(const float num)
{
	int64_t result = static_cast<int64_t>(roundf((num) * (1 << fract_bits)));
	if ((int)result != result)
	{
		std::cerr << "Overflow occured" << std::endl;
		throw std::out_of_range("overflow occured");
	}
	else
	{
		std::cout << "Int constructor called" << std::endl;
		_value = static_cast<int>(result);
	}
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		_value = obj._value;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << fract_bits);
}

int Fixed::toInt(void) const
{
	return _value >> fract_bits;
}

