#include "Histogram.h"

int main() {
    /*
    {
        Histogram hist; //Konstruktor domyœlny
        Histogram hist_2(std::vector<int>({ 10,15,6,9,10,12 }));
        hist.emplace(20); //dodaje ocenê 20pkt

        hist.emplace(std::vector<int>({ 10, 15, 6, 9, 10, 12 }));

        hist << 10 << 12 << 20 << 21; // kolejne elementy zawieraj¹ punktacjê poszczególnych studentów

        std::cin >> hist; // pobiera dane od u¿ytkownika (pobieraj¹c najpierw liczbê wyników, które chce wprowadziæ)

        hist.from_csv(R"(../wyniki.csv)", ',', 4); //wczytuje plik csv, argumentami s¹ nazwa pliku, separator kolumn oraz index kolumny w której znajduj¹ siê dane dla histogramu

        hist_2.clear(); //usuwa wszystkie dane z histogramu 

        using Bin = int; // alias typu wartoœci dla przedzia³u histogramu
        using Frequency = int; // alias typu wartoœci dla czêstoœci wyst¹pieñ
        std::cout << hist; // zapis histogramu do strumienia tekstowego

        std::ofstream file("histogram.txt");
        file << hist; // zapis histogramu do pliku (identycznie jak dla wyœwietlenia go na konsoli)

        int freq = hist[10.5]; // zwraca czêstoœæ dla przedzia³u do którego nale¿y wartoœæ 10.5

        std::pair<Bin, Bin> range = hist.range(); // zwraca pocz¹tkowy i koñcowy przedzia³.

        std::pair<Bin, Frequency> max = hist.max(); // zwraca najczêœciej wystêpuj¹cy przedzia³ oraz jego czêstoœæ

        std::vector<Bin> bins = hist.unique_bins(); // zwraca listê unikalnych, niepustych przedzia³ów

        std::vector<std::pair<Bin, Frequency>> items = hist.unique_items(); // zwraca listê niepustych przedzia³ów oraz czêstoœæ wyst¹pieñ

        //konwersja na inne typy
        using BinsVector = std::vector<std::pair<Bin, Frequency>>;
        BinsVector items_vect = static_cast<BinsVector>(hist); // operator rzutowania dzia³a tak samo jak  Histogram::unique_items
        print(items_vect); // zewnêtrzna funkcja wyœwietlaj¹ca wektor elementów histogramu// jeœli dane nie zostan¹ usuniête kolejne wywo³ania operatora zapisu do strumienia lub
    }
    */

    using operation = float (*)(float a, float b); // definicja typu
    operation ptr; // deklaracja zmiennej typu wskaŸnik do funkcji

    ptr = sum; // przypisuje funkcjê sum
    std::cout << ptr(3, 3); // wyswietli 6 - dodawanie

    ptr = mul; // przypisuje funkcjê mul
    std::cout << ptr(3, 3); // wyswietli 9 - mno¿enie

    ptr = [](float a, float b) { return a - b; }; // przypisuje wyra¿enie lambda
    std::cout << ptr(3, 3); // wyswietli 0 - odejmowanie za pomoc¹ wyra¿enia lambda


    using operation2 = int (*)(int a, int b); // definicja typu
    operation2 ptr2;
    ptr2 = [](int a, int b) { return (-a + rand() % b); };

    // Histogram hist_3 = Histogram::generate(100, ptr2(10,10));

    auto A = createMatrix<int>(5, 6);
    auto B = copy(A);

    /*Histogram<int> histogram_int;
    Histogram<float> histogram_float;
    Histogram<std::string> histogram_of_names;

    histogram_int.emplace(5);
    histogram_float.emplace(12.3f);

    histogram_of_names.emplace("John");
    histogram_of_names.emplace("John");
    histogram_of_names.emplace("John");
    histogram_of_names.emplace("Maria");
    histogram_of_names.emplace("Maria");

    std::pair<std::string, int> mostFrequent = histogram_of_names.max();
    // lub
    auto mostFrequent2 = histogram_of_names.max();
    */
    return 0;
}
