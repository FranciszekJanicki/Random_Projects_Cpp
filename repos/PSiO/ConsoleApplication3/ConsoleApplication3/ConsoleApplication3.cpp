#include <vector>
#include <iostream>
#include <cmath>
#define M_PI 3.141592653589793238462643383279502884

void printVector(const std::vector<int>& param) {
	for (auto& n : param) {
		std::cout << n << std::endl;
	}
}

void fillProgressive1(std::vector<int>& param) {
	int n = 5;
	param.clear();
	for (size_t i = 0; i < n; ++i) {
		param.emplace_back(i);
	}
}

void fillProgressive2(std::vector<int>& param) {
	int n = 5, i = 0;
	param.clear();
	while (i < n) {
		param.emplace_back(i);
		i++;
	}
}

void fillProgressive3(std::vector<int>& param) {
	int n = 5, i = 0;
	param.resize(n);
	for (auto& n : param) {
		n = i;
		i++;
	}
}

void fillProgressive4(std::vector<int>& param) {
	int n = 5, i = 0;
	param.resize(n);
	while (i < param.size()) {
		param[i] = i;
		i++;
	}
}

std::vector <int> copyVector(const std::vector<int>& param) {
	std::vector <int> val = param;
	for (auto& n : val) {
		n = 5;
	}
	return val;
}

void min_max(const std::vector <double>& values, double& min, double& max) {
	for (auto& n : values) {
		if (n > max) {
			max = n;
		} 
		else if (n < min) {
			min = n;
		}
	}
	std::cout << min << " " << max << '\n';
}

uint64_t factorial(const int& n) {
	if (n == 0) return 1;
	else return n * factorial(n-1);
}

uint64_t factorial2(const int& n) {
	uint64_t result = 1;
	int i = 1;

	while (i <= n) {
		result *= i;
		i++;
	}
	return result;
}

bool isPrime(const int& arg) {
	if ((arg % 2 == 0) && (arg % 3 == 0) 
		&& (arg % 5 == 0) && (arg % 7 == 0)) return true;
	else false;
}

double piLeibniz(const double& stopAt) {
	double result = 0, i = 1, add = 1;
	int n = 0;
	while (add >= stopAt) {
		add = 1 / i;
		if (n % 2 == 0) {
			result += add;
		}
		else result -= add;
		i += 2;
		n++;
	}
	return result * 4;
}

void drawSquare(const int& val, bool left_diagonal, bool right_diagonal) {
	for (unsigned int i = 0; i < val; ++i) {
		for (unsigned int j = 0; j < val; ++j) {
			if (i == 0 || i == val - 1 || j == 0 || j == val - 1 || (left_diagonal && i == j) || (right_diagonal && i + j == val - 1))
				std::cout << "#";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

//oblicz c jako resztê z dzielenia a przez b
//zast¹p a liczb¹ b, nastêpnie b liczb¹ c
//je¿eli wartoœæ b wynosi 0, to a jest szukan¹ wartoœci¹ NWD, w przeciwnym wypadku przejdŸ do kroku 1

int getGCD(const int& _a, const int& _b) {
	int a = _a;
	int b = _b;
	int c = 0;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {

	/*std::vector <int> myVector;
	fillProgressive4(myVector);
	printVector(myVector);
	std::vector <int> copy = copyVector(myVector);
	printVector(copy);
	*/

	double min = 0.0;
	double max = 0.0;
	std::vector<double> values = { -1.0, 100, 3.14, -999.9, 21.37 };
	min_max(values, min, max);

	uint64_t result = factorial2(15);
	std::cout << result << '\n'; // wynik: 1307674368000

	int prime_or_not_prime = 13;
	if (isPrime(prime_or_not_prime)) {
		std::cout << prime_or_not_prime << " is prime!" << '\n';
	}
	else {
		std::cout << prime_or_not_prime << " is not prime!" << '\n';
	}

	double stopAt = 0.001;
	double piApprox = piLeibniz(stopAt);
	std::cout << piApprox << '\n';
	std::cout << "error: " << piApprox - M_PI << '\n';

	drawSquare(10, true, true);

	const int a = 6, b = 36;
	double gcd = getGCD(a, b);
	std::cout << gcd;

	return 0;
}
