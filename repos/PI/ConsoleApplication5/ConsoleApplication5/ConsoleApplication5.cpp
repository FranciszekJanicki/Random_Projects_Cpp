#include "Human.h"
#include "Bird.h"
#include "Animal.h"

/*class BaseClass {
public:
    BaseClass() {
        cout << "BaseClass constructor \n";
    }
    virtual ~BaseClass() {
        cout << "BaseClass destructor \n";
    }
    virtual void GetData2() {
        cout << "Method GetData of BaseClass \n";
    }
};

class DerivativeClass : public BaseClass {
public:
    DerivativeClass() {
        cout << "DerivativeClass constructor \n";
    }
    ~DerivativeClass() {
        cout << "DerivativeClass destructor b \n";
    }
    void GetData() {
        cout << "Method GetData of DerivativeClass \n";
    }
};
*/

int main() {
    int tableSize = 0;
    vector <Animal*> ptrTable(tableSize);

    for (unsigned int i = 0; i < 10; ++i) {

        ptrTable.emplace_back(RandomObjectGenerator());
        tableSize++;

        if (ptrTable[i] != nullptr) {
           cout << ptrTable[i]->GetType() << '\n';
        }
        else {
            cout << "nullptr!!! \n";
        }
    }
    for (unsigned int i = 0; i < tableSize; ++i) {
        ptrTable[i] = nullptr;
        delete(ptrTable[i]);
    }
    return 0;
}