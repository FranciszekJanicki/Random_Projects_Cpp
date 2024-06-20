#include "Libraries.h"

Simulation::Simulation() {
	stackObject = new Stack();
	N = stackObject->getSize();
	std::cout << "Simulation class constructor \n";
}

Simulation::~Simulation() {
	std::cout << "Simulation class destructor \n";
	stackObject = nullptr;
	delete(stackObject);
}

void Simulation::simulationMethod() {
	for (unsigned int i =0 ; i <= this->N; ++i) {
		try {
			stackObject->Push(i, i);
		}
		catch (Exception* ptr) {
			std::cout << "Error number: " << ptr->getNum() << " , Error Data: " << ptr->getData() << '\n';
		}
	}
	for (unsigned int i = 0; i <= this->N; ++i) {
		try {
			stackObject->pop(i);
		}
		catch (Exception* ptr) {
			std::cout << "Error number: " << ptr->getNum() << " , Error Data: " << ptr->getData() << '\n';
		}
	}
}
