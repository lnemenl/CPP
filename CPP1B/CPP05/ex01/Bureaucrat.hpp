/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:29:21 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/20 12:01:59 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form; //Forward declaration: allows to use Form* or Form& without including Form.hpp

// Project Rule: Bureaucrat must have a constant name and a grade in [1, 150].
class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& obj) = default;
        Bureaucrat& operator=(const Bureaucrat& obj);
        ~Bureaucrat() = default;
        // Parameterized constructor
        explicit Bureaucrat(const std::string& name, int grade);

        //const reference for string to avoid copy, const for method to promise no modification.
        const std::string& getName() const;
        int getGrade() const;

        //These methods change the grade, so not const.
        void incrementGrade();
        void decrementGrade();

        void signForm(Form& form); // Pass by reference to modify the Form

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const noexcept override;
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const noexcept override;
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
