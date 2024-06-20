#pragma once
#include <iostream>
#include <vector>
#include <random>

class ElectricPart {
protected:
	int current, voltage;
	std::string param;
public:
	std::string name;
	virtual void Force(int Vol = 0, int Cur = 0) = 0;
	friend int friendFunction(ElectricPart* ptr1, ElectricPart* ptr2);
};

int friendFunction(ElectricPart* ptr1, ElectricPart* ptr2);

void PrintData(int n);

int RandomNumber();