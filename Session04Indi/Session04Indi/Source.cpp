#include <iostream>
#include <string>
#include "Cas.h"
#define POCET_PRVKU 10

using namespace std;

// Vytvoøte funkci SeraditPole(IComparable** pole, int velikostPole)
void SeraditPole(IComparable** pole, int velikostPole) { // Seøadí pole prvkù (ukazatelù na objekt) vámi implementovaným algoritmem. Pro porovnání prvkù využijte metody compareTo().
	
	for (int i = 1; i < velikostPole; i++){
		for (int j = 0; j < i ; j++){
			if (pole[j]->compareTo(pole[i])==1) {
				 IComparable* tmp = pole[j];
				pole[j] = pole[i];
				pole[i] = tmp;
			}
		}
	}

}

//Ve funkci main() dynamicky alokujte pole ukazatelù(10 prvkù) na rozhraní IComparable.Náhodnì
//nagenerujte dynamické instance èasù a vložte je do pole.Seøaïte pole a vypište obsah seøazeného
//pole do konzole(pomocí toString())

int main(int argc, char** argv) {
	IComparable ** poleUk = new IComparable*[POCET_PRVKU];
	poleUk[0] = new Cas(5, 5, 22);
	poleUk[1] = new Cas(5, 5, 14);
	poleUk[2] = new Cas(10, 23, 13);
	poleUk[3] = new Cas(10, 34, 05);
	poleUk[4] = new Cas(8, 05, 41);
	poleUk[5] = new Cas(21, 23, 40);
	poleUk[6] = new Cas(11, 41, 07);
	poleUk[7] = new Cas(22, 19, 40);
	poleUk[8] = new Cas(11, 23, 10);
	poleUk[9] = new Cas(20, 23, 00);

	for (int i = 0; i < POCET_PRVKU; i++){
		cout << poleUk[i]->toString() << endl;
	}

	SeraditPole(poleUk, POCET_PRVKU);

	for (int i = 0; i < POCET_PRVKU; i++) {
		cout << poleUk[i]->toString() << endl;
	}

	for (int i = 0; i < POCET_PRVKU; i++){
		delete[] poleUk[i];
	}
	delete[] poleUk;
}



