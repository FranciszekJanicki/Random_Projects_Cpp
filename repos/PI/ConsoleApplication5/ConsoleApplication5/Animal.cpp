#include "Animal.h"
#include "Bird.h"
#include "Human.h"
#include "Mammal.h"

Animal::Animal() {
	cout << "Constructor of Animal class \n";
}

Animal::~Animal() {
	cout << "Destructor of Animal class \n";
}

string Animal::GetType() {
	char Type = this->animalType;

	switch (Type) {
	case 'M': return "Mammal class object \n";
		break;
	case 'H': return "Human class object \n";
		break;
	case 'B': return "Bird class object \n";
		break;
	default: return "Unitendified animal object \n";
		break;
	}
}

int RandomNumberGenerator() {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 4);
	return dist(rng);
}

Animal* RandomObjectGenerator() {
	int n = RandomNumberGenerator();

	switch (n) {
	case 0: return new Animal;
		break;
	case 1: return new Mammal;
		break;
	case 2: return new Human;
		break;
	case 3: return new Bird;
		break;
	case 4: return nullptr;
	}
}
