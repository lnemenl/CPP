/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:13:17 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/12 14:43:05 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	protected:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain& obj);
		Brain& operator=(const Brain& obj);
		~Brain();

		void setIdea(int index, const std::string& idea);
		const std::string getIdea(int index) const;
};

#endif