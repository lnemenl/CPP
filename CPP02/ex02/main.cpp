/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:40:59 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/04 16:45:39 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << "a   is: " << a << std::endl;
    std::cout << "++a is: " << ++a << std::endl;
    std::cout << "a   is: " << a << std::endl;
    std::cout << "a++ is: " << a++ << std::endl;
    std::cout << "a   is: " << a << std::endl;
    std::cout << "b   is: " << b << std::endl;
    std::cout << "max is: " << Fixed::max(a, b) << std::endl;
    std::cout << "min is: " << Fixed::min(a, b) << std::endl;

    //Arithmetic operator tests
    Fixed x(10);
    Fixed y(3.5f);
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;
    std::cout << "x / y = " << (x / y) << std::endl;

    //Comparison operator tests
    std::cout << "x > y: " << (x > y) << std::endl;
    std::cout << "x < y: " << (x < y) << std::endl;
    std::cout << "x >= y: " << (x >= y) << std::endl;
    std::cout << "x <= y: " << (x <= y) << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;
    std::cout << "x != y: " << (x != y) << std::endl;

    //min/max const tests
    const Fixed cx(7.7f), cy(8.8f);
    std::cout << "const max: " << Fixed::max(cx, cy) << std::endl;
    std::cout << "const min: " << Fixed::min(cx, cy) << std::endl;

    //Division by zero test
    try
	{
        Fixed zero(0);
        std::cout << "x / zero = " << (x / zero) << std::endl;
    }
	catch (const std::exception& ex)
	{
        std::cout << "Exception for division by zero: " << ex.what() << std::endl;
    }

    //Overflow tests
    try
	{
        Fixed big(std::numeric_limits<int>::max() >> Fixed::getFractionalBits());
        std::cout << "big: " << big << std::endl;
        std::cout << "big + big: " << (big + big) << std::endl;
    }
	catch (const std::exception& ex)
	{
        std::cout << "Exception for big + big: " << ex.what() << std::endl;
    }

    try
	{
        Fixed small(std::numeric_limits<int>::min() >> Fixed::getFractionalBits());
        std::cout << "small: " << small << std::endl;
        std::cout << "small - big: " << (small - Fixed(1)) << std::endl;
    }
	catch (const std::exception& ex)
	{
        std::cout << "Exception for small - 1: " << ex.what() << std::endl;
    }

    //Increment/Decrement overflow tests
    try
	{
        Fixed inc(std::numeric_limits<int>::max());
        std::cout << "Trying to increment max int..." << std::endl;
        ++inc;
    }
	catch (const std::exception& ex)
	{
        std::cout << "Exception for ++max: " << ex.what() << std::endl;
    }

    try
	{
        Fixed dec(std::numeric_limits<int>::min());
        std::cout << "Trying to decrement min int..." << std::endl;
        --dec;
    }
	catch (const std::exception& ex)
	{
        std::cout << "Exception for --min: " << ex.what() << std::endl;
    }

    return 0;
}