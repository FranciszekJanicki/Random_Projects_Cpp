#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

enum class PlantType { 
    Fruit, 
    Vegetable
};

class Plant {
    PlantType type;
    std::string name;
public:
    Plant(PlantType p, std::string s= "noname");
    Plant() = default;
    void setType(const PlantType& type_);
    void setName(const std::string& name_);
    PlantType getType() const;
    std::string getName() const;
    bool operator<(const Plant& other) const;
    //friend std::ostream& operator<<(std::ostream& out, const Plant& plant);
    //friend std::ostream& operator<<(std::ostream& out, const Basket& basket);
};

using Basket = std::vector<Plant>;

void addToBasket(Basket& basketCollection, const PlantType& type,
    const std::string& name);

Basket createRandomBasket(const int& items);

bool isPearl(const Basket& basket);

bool onlyFruits(const Basket& basket);

bool onlyVeggies(const Basket& basket);

bool zeroFruits(const Basket& basket);

bool zeroVeggies(const Basket& basket);

bool atLeastOneFruit(const Basket& basket);

bool atLeastOneVeggie(const Basket& basket);

auto countFruits(const Basket& basket);

auto countVeggies(const Basket& basket);

void removeStartingWith(Basket& basket, const char& letter);

Basket basketsIntersection(const Basket& basket1, const Basket& basket2);

Basket basketsDifference(const Basket& basket1, const Basket& basket2);

Basket sumBaskets(const Basket& basket1, const Basket& basket2);