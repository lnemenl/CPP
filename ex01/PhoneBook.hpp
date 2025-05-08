/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:11:11 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/08 08:45:46 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <limits>
#include <iostream>


class PhoneBook
{
    private:
        Contact contacts[MAX_CONTACTS];
        int contactCount;
        int nextIndex;
        
    public:
        PhoneBook();
        void addContact();
        void searchContact() const;
};

#endif