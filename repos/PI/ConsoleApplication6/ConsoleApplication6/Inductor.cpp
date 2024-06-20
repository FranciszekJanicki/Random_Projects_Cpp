#include "Inductor.h"

Inductor::Inductor() {
	param = "inductance";
	name = "Inductor";
}

void Inductor::Force(int Vol, int Cur) {
	current = Cur;
	voltage = Vol;
	std::cout << name << " " << param << '\n';
	std::cout << "Voltage = " << voltage << " " << "Current = " << current << '\n';
}