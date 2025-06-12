/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:18:38 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/12 12:21:21 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>

class Animal
{
    protected:
        std::string type;
        
    public:
        Animal();
        Animal(const Animal& obj);
        Animal& operator=(const Animal& obj);
        virtual ~Animal();

        virtual void makeSound() const;
        std::string getType() const;
};

#endif

