/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:11:11 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/05 16:40:32 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[MAX_CONTACTS];
        int contactCount;
        int nextIndex;
        
    public:
        PhoneBook(): contactCount(0), nextIndex(0) {}
        void addContact();
        void searchContact() const;
}