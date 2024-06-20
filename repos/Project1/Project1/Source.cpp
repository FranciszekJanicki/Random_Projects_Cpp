#include <iostream>
#include <vector>

unsigned int getNumber() {
	unsigned int number = 0;
	do {
		std::cout << "type how many inputs: "; std::cin >> number;
	} while (number < 0);
		return number;
}

bool getInput() {
	int input = 0;
	std::cout << "type input: "; std::cin >> input;
	if (input >= 1) return true;
	else return false;
}

bool getLogicMultip(const bool& a, const bool& b) {
	return a && b;
}

bool getLogicSum(const bool& a, const bool& b) {
	return a || b;
}

struct bits {
	unsigned int bit : 2;
	bits() = default;
};
// bits can be only declared as a part of structure
// you cant have an array of bits, pointer to bits, function returning bits
// int, signed int, unsigned int are types of bits, : n is width of bit variable, but it has to be less or equal number
// as bits of type of value, example int has 8 bits so max 8 bits, signed int has 32 bits, so max 32 bits

struct myBits{
	unsigned int bit : 32;
} array[5]; // defines array of 5 elements with myBits objects in it

struct myStruct {
	signed int var1 : 2;
	signed int var2 : 4;
	struct myStruct* next;
} var; // defines object of structure myStruct. 
// So you can now refer to this structure as 'var' because the object is already created

struct bitField {
	unsigned int a : 4;
	unsigned int b : 5;
	unsigned int c : 7;
} *ptr; // ptr to bitField object, object of this struct can have 4+5+7 bits, so 16 combined in this structure

int main() {
	//std::vector <bool> inputs;
	//inputs.resize(getNumber());
	//for (auto i : inputs) {
	//	i = getInput();
	//}
	///*

	//for (unsigned int i = 0; i < inputs.size(); ++i) {
	//	inputs.emplace_back(getInput());
	//}
	//*/
	//bool c = getLogicMultip(inputs[0], inputs[1]);
	//bool Q = getLogicSum(c, 1);

	//std::cout << Q;
	// booleans: || or, && and
	bool a = false, b = true;
	bool d = a || b;
	std::cout << "d: " << d << std::endl;


	// bits: | or, & and, ^ xor
	bits myBit;
	myBit.bit = 1;
	bits myBit2;
	myBit2.bit = myBit.bit | 1 & 0;

	std::cout << myBit2.bit;

	//// this will give error!!!
	//bits array[20][1];
	//for (unsigned int i = 0; i < 20; ++i) {
	//	bits bit;
	//	array[i][1] = bit; // you cant store bits in array !!!
	//}
	;
	for (auto a : array) {
		std::cout << a.bit << std::endl;
	}

	var.var1 = 1;
	var.var2 = 2;
	var.next = nullptr;
	var.var1 = var.var1 ^ var.var2;
	std::cout << var.var1 << std::endl;

	ptr = new bitField; // the ptr of the bitField type is declared with struct, but you still need to point it (constructor) 
	ptr->a = 2;
	ptr->b = 31;
	ptr->c = 0;
	std::cout << ptr->a << " " << (ptr->b | ptr->a) << " " << (ptr->c & ptr->a);
	delete ptr; // delete ptr!!!

	return 0;
}