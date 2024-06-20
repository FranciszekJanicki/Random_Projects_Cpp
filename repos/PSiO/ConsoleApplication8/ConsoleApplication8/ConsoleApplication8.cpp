#include "Matrix.h"

int main() {
    // tworzy macierze 3x3
   Matrix<double> M(3, 3);
    Matrix<double> C({ {1, 0, 0},
                      {0, 1, 0},
                      {0, 0, 1} });
    Matrix<double> D;

    //std::cin >> D; // pobiera dane od u�ytkownika (zar�wno jej wymiar jak i warto�ci poszczeg�lnych element�w)

    Matrix<int>  X = Matrix<int>::getEye(3, 3); // metoda statyczna, zwraca macierz jednostkow�
    //std::cout << X << std::endl;

    // inicjalizacja zmienn� losow�
    static std::default_random_engine e{};
    std::uniform_int_distribution<int> distribution{ 0, 100 };
    Matrix<int>  Y = Matrix<int>::fill(3, 3, [&distribution]() { return distribution(e); }); // metoda statyczna, zwraca macierz o wymiarze 3x3, wype�nion� warto�ciami generowanymi przez funkcj� b�d�c� trzecim argumentem

    Matrix<double>  B;
    //B = 5.0 * M * D * 5.0 + Matrix<double>::getEye(3, 3); // operacje arytmetyczne na macierzach - zdefiniuj wszystkie niezb�dne operatory
    //std::cout << B << std::endl;
}