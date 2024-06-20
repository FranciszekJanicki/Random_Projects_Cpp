#pragma once
#include <iostream>
#include <random>

class Animal {
	int myPrivateNumber = 0;
	int RandomGenerator();
	static int counter;
	double weight, age;

protected:
	double getWeight() const;
	int getPrivate() const;
	void setPrivate(int newValue);
	void Live(int number);

public:
	Animal();
	~Animal(); //constructors/ destructors always public (or virtual)
};

class Fish : public Animal {
public:
	using Animal::Live;
};

class Bird : public Animal {
public:
	using Animal::Live;
};

class Mammal : public Animal {
public:
	using Animal::Live; // protected from base class -> public in derative class
};
