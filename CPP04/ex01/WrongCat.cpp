#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "[WrongCat] constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj)
{
	std::cout << "[WrongCat] copy constructor called" << obj.type << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	if (this != &obj)
		WrongAnimal::operator=(obj);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "[MEOW] sound" << std::endl;
}