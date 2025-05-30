/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:39:12 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/30 15:46:12 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>


class Fixed
{
    private:
        int _value;
        static const int fract_bits = 8;
        
    public:
        Fixed();
        Fixed (const Fixed& obj);
        Fixed& operator=(const Fixed& obj);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};