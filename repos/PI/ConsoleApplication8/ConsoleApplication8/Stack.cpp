#include "Libraries.h"

Stack::Stack() {
	size = 10;
	dynamicTable = new int[size];
	std::cout << "Stack class constructor \n";
}

Stack::~Stack() {
		dynamicTable = nullptr;
		delete(dynamicTable);
	std::cout << "Stack class destructor \n";
}

void Stack::Push(const int& arg, const int& i) {
	dynamicTable[i] = arg;
	if (i > size-1) {
		Exception* exceptionObject;
		exceptionObject = new Exception(1, "ERROR OF PUSH METHOD");
		throw exceptionObject;
	}
}

int Stack::pop(int i) {
	if (i > size-1) {
		Exception* exceptionObject;
		exceptionObject = new Exception(2, "ERROR OF POP METHOD");
		throw exceptionObject;
	}
	return this->dynamicTable[i];
}

int Stack::getSize() {
	return size;
}