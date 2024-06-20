#include <iostream>
#include <random>

class MyClass {
	std::string name, surname;
	char gender;
	int id = 0;
	static int counter, lastID;

public:
	MyClass(std::string N, std::string S, char G);
	MyClass();
	~MyClass();

	static int getLastID();
	static int getCount();
	void printData();
	int randomNumber();
};
