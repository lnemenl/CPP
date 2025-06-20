/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:29:32 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/20 12:02:45 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

    // Test Bureaucrat signing Form
    Bureaucrat alice("Alice", 50);
    Bureaucrat bob("Bob", 140);
    Form formA("FormA", 100, 50);
    Form formB("FormB", 130, 50);

    std::cout << "\nForm Signing Tests" << std::endl;
    std::cout << alice << std::endl;
    std::cout << bob << std::endl;
    std::cout << formA << std::endl;
    std::cout << formB << std::endl;

    alice.signForm(formA); //should succeed
    bob.signForm(formA);   //should fail (grade too low)
    bob.signForm(formB);   //should succeed
    std::cout << formA << std::endl;
    std::cout << formB << std::endl;
}

