/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:41:09 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/04 16:42:43 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::getFractionalBits()
{
	return fract_bits;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << fract_bits);
}

int Fixed::toInt(void) const
{
	return _value >> fract_bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}

Fixed::Fixed(const int num)
{
	int64_t result = static_cast<int64_t>(num) << fract_bits;
	if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
	{
		std::cerr << "Overflow occured" << std::endl;
		throw std::out_of_range("overflow occured");
	}
	//std::cout << "Int constructor called" << std::endl;
	_value = static_cast<int>(result);
}

Fixed::Fixed(const float num)
{
	int64_t result = static_cast<int64_t>(roundf((num) * (1 << fract_bits)));
	if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
	{
		std::cerr << "Overflow occured" << std::endl;
		throw std::out_of_range("overflow occured");
	}
	//std::cout << "Int constructor called" << std::endl;
	_value = static_cast<int>(result);
}

/*---------------------------Orthodox Canonical form---------------------------*/

Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		_value = obj._value;
	}
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
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
    int64_t result = static_cast<int64_t>(this->_value) + static_cast<int64_t>(obj._value);
    if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
	{
        std::cerr << "Overflow occurred" << std::endl;
        throw std::out_of_range("overflow occurred");
    }
    Fixed sum;
    sum._value = static_cast<int>(result);
    return sum;
}

Fixed Fixed::operator-(const Fixed& obj) const
{
	int64_t result = static_cast<int64_t>(this->_value) - static_cast<int64_t>(obj._value); 
	if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
	{
		std::cerr << "Overflow occured" << std::endl;
		throw std::out_of_range("overflow occured");
	}
	Fixed subtract;
	subtract._value = static_cast<int>(result);
	return subtract;
}

Fixed Fixed::operator*(const Fixed& obj) const
{
	int64_t result = (static_cast<int64_t>(this->_value) * static_cast<int64_t>(obj._value)) >> fract_bits;
	if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
	{
		std::cerr << "Overflow occured" << std::endl;
		throw std::out_of_range("overflow occured");
	}
	Fixed mult;
	mult._value = static_cast<int>(result);
	return mult;
}

Fixed Fixed::operator/(const Fixed& obj) const
{
	if (obj._value == 0)
	{
		std::cerr << "Cannot divide by 0" << std::endl;
		throw std::invalid_argument("division by zero");
	}
		
	int64_t result = (static_cast<int64_t>(this->_value) << fract_bits) / static_cast<int64_t>(obj._value); 
	if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
	{
		std::cerr << "Overflow occured" << std::endl;
		throw std::out_of_range("overflow occured");
	}
	Fixed div;
	div._value = static_cast<int>(result);
	return div;
}

/*-----------------------------------I/D operators-----------------------------------*/

//Prefix Increment (++x)
Fixed&	Fixed::operator++()
{
	if (_value == std::numeric_limits<int>::max())
	{
		std::cerr << "Overflow occured in prefix increment" << std::endl;
		throw std::out_of_range("overflow occured"); 
	}
	++_value;
	return *this;
}

//Postfix increment (x++)
Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	if (_value == std::numeric_limits<int>::max())
	{
		std::cerr << "Overflow occured in postfix increment" << std::endl;
		throw std::out_of_range("overflow occured");
	}
	++_value;
	return temp;
}

//Prefix decrement(--x)
Fixed&	Fixed::operator--()
{
    if (_value == std::numeric_limits<int>::min())
	{
        std::cerr << "Overflow occurred in prefix decrement" << std::endl;
        throw std::out_of_range("overflow occurred");
    }
    --_value;
    return *this;
}

//Postfix decrement(x--)
Fixed	Fixed::operator--(int)
{
    Fixed temp(*this);
    if (_value == std::numeric_limits<int>::min())
	{
        std::cerr << "Overflow occurred in postfix decrement" << std::endl;
        throw std::out_of_range("overflow occurred");
    }
    --_value;
    return temp;
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