/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:18:12 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/14 11:49:06 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// const Animal* a = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();

	std::cout << "=== Polymorphic Sound Test ===" << std::endl;
	
	std::cout << cat->getType() << ": ";
	cat->makeSound();

	std::cout << dog->getType() << ": ";
	dog->makeSound();

	delete cat;
	delete dog;

	std::cout << "\n=== Deep Copy Validation ===\n" << std::endl;
	
	Cat* originalCat = new Cat();
	originalCat->setIdea(0, "Idea 1");
	originalCat->setIdea(1, "Idea 2");

	Cat* clonedCat = new Cat(*originalCat); // Copy constructor

	std::cout << "Original idea[0]: " << originalCat->getIdea(0) << std::endl;
	std::cout << "Cloned idea[0]:   " << clonedCat->getIdea(0) << std::endl;

	originalCat->setIdea(0, "Idea 3");

	std::cout << "\nAfter modifying original:\n" << std::endl;
	std::cout << "Original idea[0]: " << originalCat->getIdea(0) << std::endl;
	std::cout << "Cloned idea[0]:   " << clonedCat->getIdea(0) << std::endl;

	delete originalCat;
	delete clonedCat;

	std::cout << "\n=== WrongAnimal (Non-Virtual) Test ===\n" << std::endl;
	
	const WrongAnimal* wrong = new WrongCat();

	std::cout << wrong->getType() << ": ";
	wrong->makeSound();

	delete wrong;

	return 0;
}
