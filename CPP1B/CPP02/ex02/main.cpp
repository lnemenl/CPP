/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:40:59 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/02 14:16:34 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main( void )
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << "a   is: " << a << std::endl;
	std::cout << "++a is: " << ++a << std::endl;
	std::cout << "a   is: " << a << std::endl;
	std::cout << "a++ is: " << a++ << std::endl;
	std::cout << "a   is: " << a << std::endl;
	std::cout << "b   is: " << b << std::endl;
	std::cout << "max is: " << Fixed::max( a, b ) << std::endl;
	std::cout << "min is: " << Fixed::min( a, b ) << std::endl;
	return 0;
}