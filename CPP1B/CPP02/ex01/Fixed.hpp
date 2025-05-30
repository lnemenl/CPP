/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:40:26 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/30 16:40:30 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

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
		Fixed(const int);
		Fixed(const float);
		float toFloat(void) const;
		int toInt(void) const;
		Fixed& operator<<(const Fixed& obj);
			
};