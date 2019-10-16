#include "IComparable.h"
#include "Cas.h"
#include <iostream>
using namespace std;

// Vytvoøte funkci SeraditPole(IComparable** pole, int velikostPole)
void SeraditPole(IComparable** pole, int velikostPole) { // Seøadí pole prvkù (ukazatelù na objekt) vámi implementovaným algoritmem. Pro porovnání prvkù využijte metody compareTo().
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

//Ve funkci main() dynamicky alokujte pole ukazatelù(10 prvkù) na rozhraní IComparable.Náhodnì
//nagenerujte dynamické instance èasù a vložte je do pole.Seøaïte pole a vypište obsah seøazeného
//pole do konzole(pomocí toString())
int main(int argc, char** argv) {
	IComparable ** poleUk = new IComparable*[10];
		
}



