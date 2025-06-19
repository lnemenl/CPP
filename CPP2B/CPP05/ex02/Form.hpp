/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:23:28 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/19 13:33:19 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;
class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		Form();
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		~Form();

		const std::string& getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool signed() const;

		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		}

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		}
};

std::ostream& operator<<(std::ostream& os, const Form& form);


#endif