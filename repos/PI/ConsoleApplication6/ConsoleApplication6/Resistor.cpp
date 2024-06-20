#include "Resistor.h"

Resistor::Resistor() {
	name = "Resistance";
	param = "resistance";
}

void Resistor::Force(int Vol, int Cur) {
	current = Cur;
	voltage = Vol;
	std::cout << name << " " << param << '\n';
	std::cout << "Voltage = " << voltage << " " << "Current = " << current << '\n';
}