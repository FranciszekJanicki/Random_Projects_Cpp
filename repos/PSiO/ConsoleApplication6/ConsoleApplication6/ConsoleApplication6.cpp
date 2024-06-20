#include "PlantType.h"

int main() {
	Basket basketCollection;

	Plant plant1;
	plant1.setType(PlantType::Fruit);
	plant1.setName("Apple");
	basketCollection.emplace_back(plant1);

	Plant plant2(PlantType::Vegetable, "Potato");
	basketCollection.emplace_back(plant2);

	addToBasket(basketCollection, PlantType::Fruit, "Banana");
	addToBasket(basketCollection, PlantType::Vegetable, "Lettuce");

	Basket randomBasket = createRandomBasket(5);

	//std::cout << plant1;
	//std::cout << basketCollection;

	return 0;
}