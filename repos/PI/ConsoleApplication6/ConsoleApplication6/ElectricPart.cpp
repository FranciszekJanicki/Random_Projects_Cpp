#include "ElectricPart.h"

int friendFunction(ElectricPart* ptr1, ElectricPart* ptr2) {
	int ans = 0;

	if (ptr1 != nullptr && ptr2 != nullptr) {
		if (ptr1->current == ptr2->current) ans = 1;
		else if (ptr1->voltage == ptr2->voltage) ans = 2;
		else if ((ptr1->current == ptr2->current) && (ptr1->voltage == ptr2->voltage)) ans = 3;
		else ans = 0;
	}
	return ans;
}

void PrintData(int n) {
	switch (n) {
	case 0: std::cout << "Series \n";
		break;
	case 1: std::cout << "Parallel \n";
		break;
	case 2: std::cout << "Parallell or Series \n";
		break;
	default: std::cout << "Not found \n";
		break;
	}
}

int RandomNumber() {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 5); 
	return dist(rng);
}