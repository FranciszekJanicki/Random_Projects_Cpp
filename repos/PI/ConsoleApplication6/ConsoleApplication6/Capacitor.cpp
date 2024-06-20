#include "Capacitor.h"

Capacitor::Capacitor() {
	param = "capacitance";
	name = "Capacitor";
}

void Capacitor::Force(int Vol, int Cur) {
	current = Cur;
	voltage = Vol;
	std::cout << name << " " << param << '\n';
	std::cout << "Voltage = " << voltage << " " << "Current = " << current << '\n';
}