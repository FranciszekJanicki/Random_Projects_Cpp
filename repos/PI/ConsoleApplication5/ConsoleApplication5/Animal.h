#pragma once
#include <iostream>
#include <vector>
#include <random>
using namespace std;

class Animal {
protected:
	char animalType = 0;
public:
	Animal();
	~Animal();
	string GetType();
};

int RandomNumberGenerator();

Animal* RandomObjectGenerator();