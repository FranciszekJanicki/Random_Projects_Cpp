#pragma once
#include "Stack.h"
#include <iostream>

class Simulation {
	Stack* stackObject;
	int N = 0;
public:
	Simulation();
	~Simulation();
	void simulationMethod();
};

