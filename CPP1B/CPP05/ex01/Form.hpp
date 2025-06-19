/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:23:28 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/19 14:40:56 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include <Bureaucrat.hpp>

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		Form();
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		~Form();
		
		explicit Form(const std::string& name, int gradeToSign, int gradeToExecute);
		const std::string& getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& b);

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

std::ostream& operator<<(std::ostream& os, const Form& f);


#endif