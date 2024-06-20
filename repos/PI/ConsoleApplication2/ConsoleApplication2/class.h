#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

class ClassName {
    //public -> all access
    //protected -> access only from derative classes
    //private -> acccess only from methods of this class
  private:
    string name, surname, number;
    int height = 0, age = 0;
    char gender = '0';
    //it's best to initialize variables

  public:
    void getData();
    void printData();
    void Save();
    void Search(string searchedNumber);
    //class's methods are like functions only for objects of this class

    friend void Save(ClassName object);
    friend bool sameNumber(string searchedNumber, ClassName object);
    //friend functions have access to all methods and variables, but work like normal global functions
};

void Search(string searchedNumber, int index, ClassName* table); // Have to initialize in header file if body is in cpp file