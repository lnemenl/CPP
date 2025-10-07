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
		const std::string& getType() const; //Returns a reference to the string type. Not possible to modify it.
};

#endif

