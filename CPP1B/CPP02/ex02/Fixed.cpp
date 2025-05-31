/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:41:09 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/31 15:18:17 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

//Orthodox Canonical form
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


//Comparison operators
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


//Arithmetic operators
Fixed& Fixed::operator+(const Fixed& obj) const
{
    Fixed sum;
    sum._value = _value + obj._value;
}

Fixed& Fixed::operator-(const Fixed& obj) const
{
    Fixed subtract;
    subtract._value = _value - obj._value;
}

Fixed& Fixed::operator*(const Fixed& obj) const
{
    Fixed mult;
    mult._value = _value * obj._value;
}

Fixed& Fixed::operator/(const Fixed& obj) const
{
    Fixed div;
    if (_value == 0)
    std::cerr << "Cannot divide by 0" << std::endl;
    div._value = _value / obj._value;
}


//I/D operators
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


//rest
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