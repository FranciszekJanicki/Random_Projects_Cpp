#pragma once

class Exception {
	int errorNumber = 0;
	std::string errorData;

public:
	Exception(int, std::string);
	~Exception();
	int getNum();
	std::string getData();
};

