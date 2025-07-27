/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:41:16 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/04 16:59:36 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>
#include <limits>

class Fixed
{
	private:
		int _value;
		static const int fract_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		~Fixed();
		
		Fixed(const int num);
		Fixed(const float num);
		float toFloat(void) const;
		int toInt(void) const;
		static int getFractionalBits();
		
		//Comparison operators
		bool	operator>(const Fixed& obj) const;
		bool	operator<(const Fixed& obj) const;
		bool	operator>=(const Fixed& obj) const;
		bool	operator<=(const Fixed& obj) const;
		bool	operator==(const Fixed& obj) const;
		bool	operator!=(const Fixed& obj) const;
		
		//Arithmetic operators
		Fixed	operator+(const Fixed& obj) const;
		Fixed	operator-(const Fixed& obj) const;
		Fixed	operator*(const Fixed& obj) const;
		Fixed	operator/(const Fixed& obj) const;
		
		//I/D operators
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		//rest
		static 	Fixed& min(Fixed& a, Fixed& b);
		static 	Fixed& max(Fixed& a, Fixed& b);
		static 	const Fixed& min(const Fixed& a, const Fixed& b); //Static means the function is called from the class, not an object.
		static 	const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
