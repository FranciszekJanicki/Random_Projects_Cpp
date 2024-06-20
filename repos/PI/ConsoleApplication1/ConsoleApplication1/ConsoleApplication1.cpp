#include <iostream>
#include <fstream>

struct contacts{
    std::string name, surname, number;
    int age;
};

void save(contacts& data) {
    std::fstream str("file.txt", std::ios::app);
    str << data.name << " " << data.surname << " " 
        << data.number << " " << data.age << std::endl;
}

void getData(contacts& person) {
    std::cout << "Type name: ";
    std::cin >> person.name;

    std::cout << "Type surname: ";
    std::cin >> person.surname;

    std::cout << "Type number: ";
    std::cin >> person.number;

    std::cout << "Type age: ";
    std::cin >> person.age;
}

void printData(contacts& person) {
    std::cout << person.name << std::endl;
    std::cout << person.surname << std::endl;
    std::cout << person.number << std::endl;
    std::cout << person.age << std::endl;
}

const int N = 2;
contacts table[N];

int main()
{
    for (int i = 0; i < std::size(table); ++i) {
        getData(table[i]); //funkcji globablnej przekazujê i'ty obiekt, który chce zmodyfikowaæ
    }

    for (int i = 0; i < std::size(table); ++i) {
        printData(table[i]);
        save(table[i]);
    }

    return 0;
}
