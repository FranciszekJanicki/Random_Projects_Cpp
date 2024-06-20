#pragma once

class Stack {
	int size = 0;
	int* dynamicTable;
public:
	Stack();
	~Stack();
	void Push(const int& arg, 
		const int& i);
	int pop(int i);
	int getSize();
};

