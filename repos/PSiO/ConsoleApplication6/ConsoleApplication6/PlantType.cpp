#include "PlantType.h"

Plant::Plant(PlantType type_, std::string name_) : 
	type(type_), name(name_) {
}

void Plant::setType(const PlantType& type_) {
	type = type_;
}

void Plant::setName(const std::string & name_) {
	name = name_;
}

PlantType Plant::getType() const {
	return type;
}

std::string Plant::getName() const {
	return name;
}

void addToBasket(Basket& basketCollection, const PlantType& type, 
	const std::string& name) {
	basketCollection.emplace_back(Plant(type, name));
}

Basket createRandomBasket(const int& items) {
	Basket ansBasket; 
	int i = 0;
	while (i < items) {
		if (i % 2 == 0) {
			ansBasket.emplace_back(Plant(PlantType::Fruit));
		}
		else ansBasket.emplace_back(Plant(PlantType::Vegetable));
		i++;
	}
	return ansBasket;
}

std::ostream& operator<<(std::ostream& out, const Plant& plant) {
	out << "Plant type: " << plant.getType() << " Plant name: " << plant.getName() << '\n';
	return out;
}

std::ostream& operator<<(std::ostream& out, const Basket& basket) {
	if (!basket.empty()) {
		for (const auto& plant : basket) {
			out << plant;
		}
	}
	else out << "Basket is empty!!! \n";
	return out;
}

bool isPearl(const Basket& basket) {
	auto is = std::find_if(basket.begin(), basket.end(), [](const Plant& plant) {
		return plant.getName() == "Pearl";});
	return is != basket.end();
}

bool onlyFruits(const Basket& basket) {
	return std::all_of(basket.begin(), basket.end(),
		[](const Plant& plant) { 
			return plant.getType() == PlantType::Fruit; });
}

bool onlyVeggies(const Basket& basket) {
	return std::all_of(basket.begin(), basket.end(),
		[](const Plant& plant) { 
			return plant.getType() == PlantType::Vegetable; });
}

bool zeroFruits(const Basket& basket) {
	return std::none_of(basket.begin(), basket.end(),
		[](const Plant& plant) { 
			return plant.getType() == PlantType::Fruit; });
}

bool zeroVeggies(const Basket& basket) {
	return std::none_of(basket.begin(), basket.end(),
		[](const Plant& plant) { 
			return plant.getType() == PlantType::Vegetable; });
}

bool atLeastOneFruit(const Basket& basket) {
	return std::any_of(basket.begin(), basket.end(),
		[](const Plant& plant) { 
			return plant.getType() == PlantType::Fruit; });
}

bool atLeastOneVeggie(const Basket& basket) {
	return std::any_of(basket.begin(), basket.end(),
		[](const Plant& plant) { 
			return plant.getType() == PlantType::Vegetable; });
}

auto countFruits(const Basket& basket) {
	return std::count_if(basket.begin(), basket.end(),
		[](const Plant& plant) { 
			return plant.getType() == PlantType::Fruit; });
}

auto countVeggies(const Basket& basket) {
	return std::count_if(basket.begin(), basket.end(),
		[](const Plant& plant) { 
			return plant.getType() == PlantType::Vegetable; });
}

void removeStartingWith(Basket& basket, const char& letter) {
	basket.erase(
		std::remove_if(basket.begin(), basket.end(),
			[&letter](const Plant& plant) { 
				return plant.getName()[0] == letter;}), basket.end());
}

bool Plant::operator<(const Plant& other) const {
	return this->getType() < other.getType();
}

Basket basketsIntersection(const Basket& basket1, const Basket& basket2) {
	Basket basket_intersection, sortedBasket1 = basket1, sortedBasket2 = basket2;
	std::sort(sortedBasket1.begin(), sortedBasket1.end(), [](const Plant& p1, const Plant& p2) {
		return p1 < p2; });
	std::sort(sortedBasket2.begin(), sortedBasket2.end(), [](const Plant& p1, const Plant& p2) {
		return p1 < p2; });

	std::set_intersection(sortedBasket1.begin(), sortedBasket1.end(),
		sortedBasket2.begin(), sortedBasket2.end(),
		std::back_inserter(basket_intersection));
	return basket_intersection;
}

Basket basketsDifference(const Basket& basket1, const Basket& basket2) {
	Basket basket_difference, sortedBasket1 = basket1, sortedBasket2 = basket2;
	std::sort(sortedBasket1.begin(), sortedBasket1.end(), [](const Plant& p1, const Plant& p2) {
		return p1 < p2; });
	std::sort(sortedBasket2.begin(), sortedBasket2.end(), [](const Plant& p1, const Plant& p2) {
		return p1 < p2; });

	std::set_difference(sortedBasket1.begin(), sortedBasket1.end(),
		sortedBasket2.begin(), sortedBasket2.end(),
		std::back_inserter(basket_difference));
	return basket_difference;
}

Basket sumBaskets(const Basket& basket1, const Basket& basket2) {
	Basket sumBasket;
	std::set_union(basket1.begin(), basket1.end(), basket2.begin(), basket2.end(),
		back_inserter(sumBasket), [](const Plant& p1, const Plant& p2) {return !(p1 < p2); });
		return sumBasket;
}
