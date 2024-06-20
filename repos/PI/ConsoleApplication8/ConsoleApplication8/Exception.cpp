#include "Libraries.h"

Exception::Exception(int arg1, std::string arg2) : 
	errorNumber(arg1), errorData(arg2) {}

Exception::~Exception() {
	std::cout << "Destructor of Exception class \n";
}

int Exception::getNum() {
	return this->errorNumber;
}

std::string Exception::getData() {
	return this->errorData;
}