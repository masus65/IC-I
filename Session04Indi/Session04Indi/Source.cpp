#include "IComparable.h"
#include "Cas.h"
#include <iostream>
using namespace std;

// Vytvo�te funkci SeraditPole(IComparable** pole, int velikostPole)
void SeraditPole(IComparable** pole, int velikostPole) { // Se�ad� pole prvk� (ukazatel� na objekt) v�mi implementovan�m algoritmem. Pro porovn�n� prvk� vyu�ijte metody compareTo().
	IComparable * pomoc;
	for (int i = 0; i < velikostPole - 1; i++){
		for (int j = 0; j < velikostPole - 1 - 1 ; j++){
			if (pole[j] > pole[j + 1]) {
				pomoc = pole[j];
				pole[j] = pole[j + 1];
				pole[j + 1] = pomoc;
			}
		}
	}

}

//Ve funkci main() dynamicky alokujte pole ukazatel�(10 prvk�) na rozhran� IComparable.N�hodn�
//nagenerujte dynamick� instance �as� a vlo�te je do pole.Se�a�te pole a vypi�te obsah se�azen�ho
//pole do konzole(pomoc� toString())
int main(int argc, char** argv) {
	IComparable ** poleUk = new IComparable*[10];
		
}



