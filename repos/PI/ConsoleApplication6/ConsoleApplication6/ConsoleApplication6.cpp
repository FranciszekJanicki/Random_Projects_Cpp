#include "ElectricPart.h"
#include "Inductor.h"
#include "Resistor.h"
#include "Capacitor.h"

int main() {

    std::vector <ElectricPart*> ptrTable(5);
    ptrTable.emplace_back(new Resistor);
    ptrTable.emplace_back(new Capacitor);
    ptrTable.emplace_back(new Inductor);
    ptrTable.emplace_back(new Resistor);
    ptrTable.emplace_back(new Capacitor);

    for (auto i : ptrTable) {
        if (i != nullptr) i->Force(RandomNumber(), RandomNumber());
    }
    
    for (int i = 0; i < ptrTable.size(); ++i) {
        for (int j = i + 1; j < ptrTable.size(); ++j) {
            PrintData(friendFunction(ptrTable[i], ptrTable[j]));
        }
    }
    for (auto i : ptrTable) {
        delete i;
    }
    return 0;
}