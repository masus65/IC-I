//#pragma once
#ifndef CAS_H
#define CAS_H
#include "IComparable.h"

//Vytvo�te strukturu Cas, kter� obsahuje priv�tn� polo�ky int _hodiny(0 - 23), _minuty(0 - 59), _sekundy (0 - 59); 
class Cas : IComparable { // Implementujte ve struktu�e rozhran� IComparable
private:
	int _hodiny;
	int _minuty;
	int _sekundy;
public:
	Cas(int _aHodiny, int _aMinuty, int _aSekundy); // V�echny atributy nastavte v konstruktoru.
	//(p�edpokl�dejte, �e Cas se bude zase jen porovn�vat s jin�m objektem stejn�ho typu, nen� nutn� kontrola typu).
};

#endif // !CAS_H


