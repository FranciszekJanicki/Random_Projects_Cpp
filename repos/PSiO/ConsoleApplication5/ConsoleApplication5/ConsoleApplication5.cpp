#include "Header.h"

int main() {
	
	/* {
		int x = 5;
		int y = 10;
		const int M = 5;

		auto add = [](int a1, int a2) { return a1 + a2; };
		int z = add(x, y);

		auto inc = [](int& a) { a++; };
		inc(x);

		auto mulM = [M](int& x) { x *= M; };
		mulM(y);
	}

	{
		std::vector<Sword> swords;

		auto is_bastard = [](const Sword& sword) {
			return sword.type == SwordType::Bastard;
			};

		auto number_of_bastard_swords = std::count_if(swords.begin(), swords.end(),
			is_bastard);

		bool contain_katana = std::any_of(swords.begin(), swords.end(),
			[](const auto& sword) {
				return sword.type == SwordType::Katana;
			});

		const float m2ft = 3.28084f; // 1 metr = 3.24084 stopy
		auto metric_to_imperial = [m2ft](Sword& sword) {
			sword.length *= m2ft;
			return sword;
			};

		std::transform(swords.begin(), swords.end(), swords.begin(),
			metric_to_imperial);
	}

	{
		const int N = 100;
		std::vector<float> numbers(N);
		std::generate(numbers.begin(), numbers.end(), randomFloat01); // Zwróæ uwagê na brak nawiasów () po `randomFloat01`.

		// 1
		std::sort(numbers.begin(), numbers.end()); // Sortuje w kolejnoœci rosn¹cej
		print(numbers);
		// 2 - równowa¿ne z 1
		std::sort(numbers.begin(), numbers.end(), lessThan); // Sortuje w kolejnoœci rosn¹cej 
		print(numbers);

		// 3
		std::sort(numbers.begin(), numbers.end(), [](float x, float y) {// Sortuje w kolejnoœci malej¹cej
			return x > y;
			});
		print(numbers);

		// 4 - równowa¿ne z 3
		std::sort(numbers.begin(), numbers.end(), greaterThan);// Sortuje w kolejnoœci malej¹cej 
		print(numbers);

		// 5 - równowa¿ne z 3 i 4
		auto greater_than = [](float x, float y) {
			return x > y;
			};
		std::sort(numbers.begin(), numbers.end(), greater_than);// Sortuje w kolejnoœci malej¹cej
		print(numbers);

	}
	*/

	const int n = 5;
	{
		std::vector<int> intTable;
		fillVector(intTable, -20, 20, n);
		deleteFromVector(intTable, 4);
		sortAscVector(intTable);
		printVector(intTable);
		std::cout << std::endl;
		printVector(countElementsVector(intTable));
	}
		std::cout << '\n' << "//////////////" << '\n' << '\n';
	{
		std::list<int> intTable2;
		fillList(intTable2, -20, 20, n);
		deleteFromList(intTable2, 3);
		sortDescList(intTable2);
		printList(intTable2);
		std::cout << std::endl;
		printList(countElementsList(intTable2));
	}

	return 0;
}