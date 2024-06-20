#include "class.h"

//metod� odpalam na danym obiekcie na kt�rym chce operowa�
//funkcji podaj� to na czym chce operowa�, tzn. obiekt, struktur�, tablic�, zmienn�, itp.
//jesli chce w funkcji wszystko robi�, to najlepiej podac tablic�, je�li chc� w mainie to wystarczy jedna kom�rka,
// a for w mainie, ale wtedy mog� tylko operowa� na tej kom�rce wewn�trz funkcji
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


