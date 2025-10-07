#include "Brain.hpp"

Brain::Brain() : ideas()
{
	std::cout << "[Brain] constructor called" << std::endl; 
}

Brain::Brain(const Brain& obj) 
{
	std::cout << "[Brain] copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		ideas[i] = obj.ideas[i];
}

Brain& Brain::operator=(const Brain& obj)
{
	std::cout << "[Brain] copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; ++i)
			ideas[i] = obj.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "[Brain] destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	return ""; // return std::string();
}
