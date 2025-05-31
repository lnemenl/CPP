/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:41:09 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/31 15:56:09 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	_value = num << fract_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(num * (1 << fract_bits)));
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << fract_bits);
}

int Fixed::toInt(void) const
{
	return _value >> fract_bits;
}

/*---------------------------Orthodox Canonical form---------------------------*/

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*-----------------------------Comparison operators-----------------------------*/

bool	Fixed::operator>(const Fixed& obj) const
{
	return _value > obj._value;
}

bool	Fixed::operator<(const Fixed& obj) const
{
	return _value < obj._value;
}

bool	Fixed::operator>=(const Fixed& obj) const
{
	return _value >= obj._value;
}

bool	Fixed::operator<=(const Fixed& obj) const
{
	return _value <= obj._value;
}

bool	Fixed::operator==(const Fixed& obj) const
{
	return _value == obj._value;
}

bool	Fixed::operator!=(const Fixed& obj) const
{
	return !(_value == obj._value);
}

/*------------------------------Arithmetic operators------------------------------*/

Fixed Fixed::operator+(const Fixed& obj) const
{
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed& obj) const
{
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed& obj) const
{
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed& obj) const
{
	if (obj._value == 0)
		std::cerr << "Cannot divide by 0" << std::endl;
	return Fixed(this->toFloat() / obj.toFloat());
}

/*-----------------------------------I/D operators-----------------------------------*/

Fixed&	Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_value++;
	return (temp);
}

Fixed&	Fixed::operator--()
{
	this->_value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_value--;
	return (temp);
}

/*---------------------------------------MIN/MAX---------------------------------------*/

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}