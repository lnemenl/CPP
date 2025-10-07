#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class Intern
{
    public:
        Intern() = default;
        Intern(const Intern& obj) = default;
        Intern& operator=(const Intern& obj) = delete;
        ~Intern() = default;

        AForm* makeForm(const std::string& formName, const std::string& target) const;

        class FormNotFoundException : public std::exception
        {
            public:
                const char* what() const noexcept override;
        };
};

#endif