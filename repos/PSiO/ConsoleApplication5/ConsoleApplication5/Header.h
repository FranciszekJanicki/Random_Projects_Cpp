#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <list>
#include <utility>
#include <functional>

enum class SwordType { 
	Bastard, 
	Great, 
	Short, 
	Katana 
};

struct Sword {
	SwordType type; // type object of enum class can only be of those defined in enum class: Bastard, Great, Short, Katana
	float length;
};

template <typename T>
bool lessThan(const T& x, const T& y);

template <typename T>
bool greaterThan(const T& x, const T& y);

float randomFloat01();

int randomInt(const int& min, const int& max);

std::pair<int, int>  getMinMax(const std::list<int>& values);

std::pair<int, int>  getMinMax2(const std::list<int>& values);

void fillVector(std::vector<int>& values, const int& min, const int& max, const int& n);

void fillList(std::list<int>& values, const int& min, const int& max, const int& n);

void printVector(const std::vector<int>& values);

void printList(const std::list<int>& values);

int getMinList(const std::list<int>& values);

int getMaxList(const std::list<int>& values);

int getMinVector(const std::vector<int>& values);

int getMaxVector(const std::vector<int>& values);

std::pair<int, int> getMinMaxList(const std::list<int>& values);

std::pair<int, int> getMinMaxVector(const std::vector<int>& values);

void deleteFromVector(std::vector<int>& values, const int& value);

void deleteFromList(std::list<int>& values, const int& value);

void sortAscList(std::list<int>& values);

void sortDescList(std::list<int>& values);

void sortAscVector(std::vector<int>& values);

void sortDescVector(std::vector<int>& values);

std::list <int> countElementsList(const std::list <int>& values);

std::vector <int> countElementsVector(const std::vector <int>& values);