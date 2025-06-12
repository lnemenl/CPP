/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:18:12 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/12 13:59:43 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n=== Polymorphic array test ===" << std::endl;

	const int size = 4;
	const Animal* animals[size];

	for (int i = 0; i < size; ++i) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < size; ++i) {
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < size; ++i)
		delete animals[i];

	std::cout << "\n=== Virtual destructor check ===" << std::endl;

	const Animal* a = new Dog();
	delete a; // Should call Dog::~Dog() then Animal::~Animal()


	

	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// i->makeSound();
	// j->makeSound();
	// meta->makeSound();
	// delete meta;
	// delete j;
	// delete i;

	std::cout << "\n=== Reference polymorphism test ===" << std::endl;

	Dog dog;
	const Animal& animalRef = dog;
	animalRef.makeSound();


	std::cout << "\n ============ WrongAnimal test ============" << std::endl;
	const WrongAnimal* wrong = new WrongCat();
	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();
	delete wrong;

	return (0);
}