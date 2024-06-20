#include "Header.h"

template <typename T>
bool lessThan(const T& x, const T& y) {
	return x < y;
}

template <typename T>
bool greaterThan(const T& x, const T& y) {
	return x > y;
}

float randomFloat01() {
	static std::default_random_engine e{ static_cast<long unsigned int>(time(0)) };
	std::uniform_real_distribution<float> d{ 0.0f, 1.0f };
	return d(e);
}

int randomInt(const int& min, const int& max) {
	static std::default_random_engine e{ static_cast<long unsigned int>(time(0)) };
	std::uniform_int_distribution<int> d{ min, max };
	return d(e);
}

std::pair<int, int> getMinMaxList(const std::list<int>& values) {
	auto minIt = std::min_element(values.begin(), values.end());
	auto maxIt = std::max_element(values.begin(), values.end());

	if (minIt != values.end() && maxIt != values.end() && !values.empty()) {
		return std::make_pair(*minIt, *maxIt);
	}
    return std::make_pair(0, 0);
}

std::pair<int, int> getMinMaxVector(const std::vector<int>& values) {
	auto minMaxPair = std::minmax_element(values.begin(), values.end());

	if (minMaxPair.first != values.end() && minMaxPair.second != values.end() && !values.empty()) {
		return std::make_pair(*minMaxPair.first, *minMaxPair.second);
	}
    return std::make_pair(0, 0);
}

int getMinList(const std::list<int>& values) {
    auto minIt = std::min_element(values.begin(), values.end());
    return *minIt;
}

int getMaxList(const std::list<int>& values) {
    auto minIt = std::max_element(values.begin(), values.end());
    return *minIt;
}

int getMinVector(const std::vector<int>& values) {
    return getMinMaxVector(values).first;
}

int getMaxVector(const std::vector<int>& values) {
    return getMinMaxVector(values).second;
}

void fillVector(std::vector<int>& values, const int& min, const int& max, const int& n) {
    values.clear();
        for (unsigned int i = 0; i < n; ++i) {
            values.emplace_back(randomInt(min, max));
    }
}

void fillList(std::list<int>& values, const int& min, const int& max, const int& n) {
    values.resize(n);
    for (auto& v : values) {
        v = randomInt(min, max);
    }
}

void printVector(const std::vector<int>& values) {
    for (const auto& v : values) {
        std::cout << v << std::endl;
    }
}

void printList(const std::list<int>& values) {
    for (auto it = values.begin(); it != values.end(); ++it)
        std::cout << *it << std::endl;
}

void deleteFromVector(std::vector<int>& values, const int& value) {
    for (auto it = values.begin(); it != values.end(); ++it)
        if (*it == value) {
            it = values.erase(it);
            values.resize(values.size() - 1);
        }
}

void deleteFromList(std::list<int>& values, const int& value) {
    while (true) {
        auto it = std::find(values.begin(), values.end(), value);
        if (it != values.end()) {
            values.erase(it);
        }
        else break;
    }
}

void sortAscList(std::list<int>& values) {
    values.sort();
}

void sortDescList(std::list<int>& values) {
    values.sort([](int x, int y) { return abs(x) > abs(y); });
}

void sortAscVector(std::vector<int>& values) {
    std::sort(values.begin(), values.end());
}

void sortDescVector(std::vector<int>& values) {
    std::sort(values.begin(), values.end(),
        [](int x, int y) {
            return abs(x) > abs(y); });
}

std::list<int> countElementsList(const std::list<int>& values) {
    std::list<int> result;
    for (const auto& value : values) {
        result.emplace_back(std::count(values.begin(), values.end(), value));
    }
    return result;
}

std::vector<int> countElementsVector(const std::vector<int>& values) {
    std::vector<int> result;
    int minValue = getMinVector(values);
    int maxValue = getMaxVector(values);
    int count = 0;
    for (auto i = minValue; i <= maxValue; ++i) {
        count = std::count(values.begin(), values.end(), i);
        if (count != 0) result.emplace_back(count);
    }
    return result;
}