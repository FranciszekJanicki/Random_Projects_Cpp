#include "class.h"

//class's methods are run on given object (this)
void ClassName::getData() {
    cout << endl << "Get name: ";
    cin >> name;

    cout << endl << "Get surname: ";
    cin >> surname;

    while (gender != 'M' && gender != 'F') {
        cout << endl << "Get gender (M/F): ";
        cin >> gender;
    }

    cout << endl << "Get number: ";
    cin >> number;

    cout << endl << "Get height: ";
    cin >> height;

    cout << endl << "Get age: ";
    cin >> age;
};

void ClassName::printData() {
  cout << endl;
  cout << "Hello" << endl;
  cout << "My name is " << name << " " << surname << number << gender << age << height << endl;
 };

void ClassName::Search(string searchedNumber) {
    if (searchedNumber == number) {
        printData();
        Save();
    }
    else {
        cout << "Number not found" << endl;
    }
}

void ClassName::Save() {
    fstream str("textFile.txt", ios::app);
    str << name << surname << number << endl;
    str.close();
}

// GLOBAL FUNCTION (USING FRIEND FUNCTIONS)
//here we see that last argument is a table of pointers of type ClassName, that's because every table is actually pointers to it's elements!
void Search(string searchedNumber, int index, ClassName* table) {
    for (int i = 0; i < index; ++i) {
        if (sameNumber(searchedNumber, table[i])) { //using bool function to make it more clear and proffesional
            Save(table[i]);
        }
        else {
            cout << "Number not found" << endl;
        }
    }
}

// FRIEND FUNCTIONS
//argument is one object, not a table of objects (pointers to it's elements), hence the lack of '*'
//friend functions is run like a normal function, if you want to perform operations on object you need to pass the object to it!
bool sameNumber(string searchedNumber, ClassName object) { 
    if (object.number == searchedNumber) {
        return true;
    }
    else return false;
}

void Save(ClassName object) {
    fstream str("textFile.txt", ios::app);
    str << object.name << object.surname << object.number << endl;
    str.close();
}