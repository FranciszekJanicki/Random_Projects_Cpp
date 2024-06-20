#include "class.h"

//metodê odpalam na danym obiekcie na którym chce operowaæ
//funkcji podajê to na czym chce operowaæ, tzn. obiekt, strukturê, tablicê, zmienn¹, itp.
//jesli chce w funkcji wszystko robiæ, to najlepiej podac tablicê, jeœli chcê w mainie to wystarczy jedna komórka,
// a for w mainie, ale wtedy mogê tylko operowaæ na tej komórce wewn¹trz funkcji
int main()
{
	const int N = 3;
	ClassName *people[N]; //creating a table of pointers to ClassName class objects

	for (int i = 0; i < N; ++i) {
		people[i] = new ClassName(); //initializing with default constructor -> must do with pointers to objects!
		people[i]->getData();
		people[i]->printData();
		//methods are working on given object, there we use an #i object
	}

	string searchedNumber = "123";

	// GLOBAL FUNCTIONS
	//Search(searchedNumber, N, people); //global function, even if friend with class, needs to know on which object we run it
	//here we pass table of pointers to objects, but even if they were objects, not pointers to objects/ structures, the table
	//of these is actually a pointers to it's cells
	
	//OR CLASS FUNCTIONS
	for (int i = 0; i < N; ++i) {
		people[i]->Search(searchedNumber);
	 }

	for (int i = 0; i < N; ++i) {
		delete(people[i]); //deleting pointers!!!
	}

	return 0;
};


