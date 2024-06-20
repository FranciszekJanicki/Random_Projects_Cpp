#include "Histogram.h"

int main() {
    /*
    {
        Histogram hist; //Konstruktor domy�lny
        Histogram hist_2(std::vector<int>({ 10,15,6,9,10,12 }));
        hist.emplace(20); //dodaje ocen� 20pkt

        hist.emplace(std::vector<int>({ 10, 15, 6, 9, 10, 12 }));

        hist << 10 << 12 << 20 << 21; // kolejne elementy zawieraj� punktacj� poszczeg�lnych student�w

        std::cin >> hist; // pobiera dane od u�ytkownika (pobieraj�c najpierw liczb� wynik�w, kt�re chce wprowadzi�)

        hist.from_csv(R"(../wyniki.csv)", ',', 4); //wczytuje plik csv, argumentami s� nazwa pliku, separator kolumn oraz index kolumny w kt�rej znajduj� si� dane dla histogramu

        hist_2.clear(); //usuwa wszystkie dane z histogramu 

        using Bin = int; // alias typu warto�ci dla przedzia�u histogramu
        using Frequency = int; // alias typu warto�ci dla cz�sto�ci wyst�pie�
        std::cout << hist; // zapis histogramu do strumienia tekstowego

        std::ofstream file("histogram.txt");
        file << hist; // zapis histogramu do pliku (identycznie jak dla wy�wietlenia go na konsoli)

        int freq = hist[10.5]; // zwraca cz�sto�� dla przedzia�u do kt�rego nale�y warto�� 10.5

        std::pair<Bin, Bin> range = hist.range(); // zwraca pocz�tkowy i ko�cowy przedzia�.

        std::pair<Bin, Frequency> max = hist.max(); // zwraca najcz�ciej wyst�puj�cy przedzia� oraz jego cz�sto��

        std::vector<Bin> bins = hist.unique_bins(); // zwraca list� unikalnych, niepustych przedzia��w

        std::vector<std::pair<Bin, Frequency>> items = hist.unique_items(); // zwraca list� niepustych przedzia��w oraz cz�sto�� wyst�pie�

        //konwersja na inne typy
        using BinsVector = std::vector<std::pair<Bin, Frequency>>;
        BinsVector items_vect = static_cast<BinsVector>(hist); // operator rzutowania dzia�a tak samo jak  Histogram::unique_items
        print(items_vect); // zewn�trzna funkcja wy�wietlaj�ca wektor element�w histogramu// je�li dane nie zostan� usuni�te kolejne wywo�ania operatora zapisu do strumienia lub
    }
    */

    using operation = float (*)(float a, float b); // definicja typu
    operation ptr; // deklaracja zmiennej typu wska�nik do funkcji

    ptr = sum; // przypisuje funkcj� sum
    std::cout << ptr(3, 3); // wyswietli 6 - dodawanie

    ptr = mul; // przypisuje funkcj� mul
    std::cout << ptr(3, 3); // wyswietli 9 - mno�enie

    ptr = [](float a, float b) { return a - b; }; // przypisuje wyra�enie lambda
    std::cout << ptr(3, 3); // wyswietli 0 - odejmowanie za pomoc� wyra�enia lambda


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
