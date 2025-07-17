/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:15:32 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/07/17 13:46:59 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./ex00 <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
