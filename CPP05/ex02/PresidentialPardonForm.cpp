/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:01:46 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/24 14:32:30 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    checkExecution(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}