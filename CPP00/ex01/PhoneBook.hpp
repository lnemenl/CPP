#pragma once
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
