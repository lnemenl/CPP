/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:29:32 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/25 17:09:04 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat john("Captain Jack Sparrow", 2);
		std::cout << john << std::endl;
		john.incrementGrade();
		std::cout << john << std::endl;
		john.incrementGrade();
		john.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}

	try
	{
		Bureaucrat jane("Captain Nemo", 149);
		std::cout << jane << std::endl;
		jane.decrementGrade();
		std::cout << jane << std::endl;
		jane.decrementGrade();
		jane.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}

	// try
	// {
	//     Bureaucrat error("Error", 200);
	// }
	// catch (const std::exception& e)
	// {
	//     std::cerr << "Caught exception: " << e.what() << '\n';
	// }

	// return 0;
}

