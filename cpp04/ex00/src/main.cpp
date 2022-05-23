#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{

	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << "get_type : i " << i->get_type() << " " << std::endl;
	std::cout << "get_type : j " << j->get_type() << " " << std::endl;

	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal *wrong = new WrongCat();

	wrong->makeSound();

	delete wrong;

	delete meta;
	delete i;
	delete j;

	return 0;
}
