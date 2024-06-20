#include "MyClass.h"

int main() {

    MyClass *member1 = new MyClass("Dupa", "Cipa", 'F');
    MyClass *member2 = new MyClass();
    MyClass *member3 = new MyClass();
    MyClass *member4 = new MyClass();

    std::vector<MyClass*> MembersTable;
    MembersTable.push_back(member1);
    MembersTable.push_back(member2);
    MembersTable.push_back(member3);
    MembersTable.push_back(member4);

    for (unsigned int i = 0; i < MembersTable.size(); ++i) {
        MembersTable[i]->printData();
    }

    std::cout << '\n' << "Last ID: " << MyClass::getLastID() << '\n';
    std::cout << "Counter: " << MyClass::getCount() << '\n' << '\n';

    for (unsigned int i = 0; i < MembersTable.size(); ++i) {
        delete(MembersTable[i]);
    }

    std::cout << '\n' << "Last ID: " << MyClass::getLastID() << '\n';
    std::cout << "Counter: " << MyClass::getCount() << '\n' << '\n';

    return 0;
}
