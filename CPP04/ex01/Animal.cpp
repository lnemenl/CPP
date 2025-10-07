#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "[Animal] default constructor called" << std::endl;
}

Animal::Animal(const Animal& obj) : type(obj.type)
{
	std::cout << "[Animal] copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
	std::cout << "[Animal] copy assignment operator called" << obj.type << std::endl;
	if (this != &obj)
		type = obj.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "[Animal] destructor called" << std::endl;
}

const std::string& Animal::getType() const
{
	return (type);
}

void Animal::makeSound(void) const
{
	std::cout << "[Animal] make sound " << std::endl;
}

