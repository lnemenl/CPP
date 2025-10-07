#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "[Cat] Contstructor called" <<std::endl;
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
	std::cout << "[Cat] copy constructor called" << obj.getType() << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
		Animal::operator=(obj);
	return *this;
}

Cat::~Cat()
{
	std::cout << "[Cat] destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "[CAT] sound" << std::endl;
}

