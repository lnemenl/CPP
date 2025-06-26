/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:02:47 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/26 09:34:14 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        //const because a form's target shouldn't change after creation
        const std::string _target;
    public:
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm&) = default;
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&) = delete;
        ~ShrubberyCreationForm() = default;
        ShrubberyCreationForm() = delete;
        void execute(Bureaucrat const& executor) const override;
};

#endif