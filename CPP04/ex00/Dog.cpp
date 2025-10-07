#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "[Dog] Contstructor called" << std::endl;
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
	std::cout << "[Dog] copy constructor called" << obj.getType() << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this != &obj)
		Animal::operator=(obj);
	return *this;
}

Dog::~Dog()
{
	std::cout << "[Dog] destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[DOG] sound" << std::endl;
}