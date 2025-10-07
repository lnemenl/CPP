#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* brain;

	public:
		Dog();
		Dog(const Dog& obj);
		Dog& operator=(const Dog& obj);
		~Dog();
		
		void makeSound() const override;
		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
};

#endif