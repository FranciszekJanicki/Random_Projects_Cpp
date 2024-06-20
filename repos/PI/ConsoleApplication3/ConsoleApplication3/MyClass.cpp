#include "MyClass.h"

MyClass::MyClass(std::string N, std::string S, char G) {
	name = N;
	surname = S;
	gender = G;
	counter++;
	id = randomNumber();
	lastID = id;

	std::cout << "MyClass constructor \n";
}
MyClass::MyClass() : MyClass("Twuj", "Stary", 'F') {
}

MyClass::~MyClass() {
	std::cout << "MyClass destructor \n";
	counter--;
}

int MyClass::counter = 0;
int MyClass::lastID = 0;

int MyClass::getLastID() {
	return lastID;
}

int MyClass::getCount() {
	return counter;
}

void MyClass::printData() {
	std::cout << '\n';
	std::cout << "Name: " << name << '\n';
	std::cout << "Surname: " << surname << '\n';
	std::cout << "ID: " << id << '\n';
}

int MyClass::randomNumber() {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distID(10000, 99999); 

	return distID(rng);
}