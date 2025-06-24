/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:02:13 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/24 15:44:31 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib> // For rand(), srand()
#include <ctime> // For time()

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    :AForm("RobotomyRequestForm", 72, 45), _target(target) {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    checkExecution(executor);

    std::cout << "Drilling noises" << std::endl;

    // Setting the starting poing for sequence only the first time when execute() is called, so that not to get the same sequence every run.
    // Creates a variable that is shared across all calls to
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(0));
        seeded = true;
    }
    
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy of " << _target << " faield." <<std::endl;
}