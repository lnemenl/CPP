/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:01:52 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/24 13:43:39 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        //const because a form's target shouldn't change after creation
        const std::string _target;
    public:
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm&) = default;
        PresidentialPardonForm& operator=(const PresidentialPardonForm&) = delete;
        ~PresidentialPardonForm() = default;
        PresidentialPardonForm() = delete;
        void execute(Bureaucrat const& executor) const override;
};

#endif