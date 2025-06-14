/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:18:12 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/06/14 11:51:25 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* animals[4];

    for (int i = 0; i < 4; ++i)
	{
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n=== makeSound Test ===\n" << std::endl;
    for (int i = 0; i < 4; ++i)
	{
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; ++i)
        delete animals[i];
	
    std::cout << "\n=== Deep Copy Test ===\n" << std::endl;
    Cat* cat1 = new Cat();
    cat1->setIdea(0, "Idea 1");
    cat1->setIdea(1, "Idea 2");

    Cat* cat2 = new Cat(*cat1); // copy constructor

    std::cout << "Cat1 idea[0]: " << cat1->getIdea(0) << std::endl;
    std::cout << "Cat2 idea[0]: " << cat2->getIdea(0) << std::endl;

    cat1->setIdea(0, "Idea 3");

    std::cout << "\nAfter modification:\n" << std::endl;
    std::cout << "Cat1 idea[0]: " << cat1->getIdea(0) << std::endl;
    std::cout << "Cat2 idea[0]: " << cat2->getIdea(0) << std::endl;

    delete cat1;
    delete cat2;

    std::cout << "\n=== WrongAnimal Test ===\n" << std::endl;

    const WrongAnimal* wrong = new WrongCat();
    std::cout << "Wrong type: " << wrong->getType() << std::endl;
    wrong->makeSound();
    delete wrong;

    return 0;
}
