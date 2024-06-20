#include "Animal.h"

int Animal::counter = 0;

Animal::Animal() : age(10), weight(15) {
	counter++;
	myPrivateNumber = RandomGenerator();
	std::cout << "There's this many animals in ZOO: " << Animal::counter << '\n';
	std::cout << "That's my ID: " << this->getPrivate() << '\n';
	std::cout << "That's my weight: " << this->getWeight() << '\n';
}

Animal::~Animal(){
	counter--;
	std::cout << "There's this many animals left: " << Animal::counter << '\n';
}

int Animal::RandomGenerator() {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(10,99);

	return dist(rng);
}

int Animal::getPrivate() const {
	return myPrivateNumber;
}

void Animal::setPrivate(int newValue) {
	myPrivateNumber = newValue;
}

void Animal::Live(int number) {
	this->setPrivate(number);
	std::cout << "That's my ID: " << this->getPrivate() << '\n';
}

double Animal::getWeight() const {
	return weight;
}