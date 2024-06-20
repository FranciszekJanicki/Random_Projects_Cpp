#include <iostream>
#include <vector>

unsigned int getNumber() {
	unsigned int number = 0;
	do {
		std::cout << "type how many inputs: " << std::cin << number;
	} while (number < 0)
		return number;
}

bool getInput(const bool & current) {
	bool input = false;
	std::cout << "type input: " << std::cin << input;
	if (input > 0) input = true;
	else input = false;
	return input;
}

int main() {
 	std::vector <bool> inputs;
	inputs.resize(getNumber())
	for (auto i : inputs) {
		i.emplace_back(getInput(i))
	}


	return 0;
}