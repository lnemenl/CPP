/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:39:12 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/27 16:46:41 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
    private:
        int _value;
        static const int fract_bits;
        
    public:
        Fixed();
        Fixed (const Fixed& obj);
        Fixed& operator=(const Fixed& obj);
        ~Fixed();
               
}