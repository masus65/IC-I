//#pragma once
#ifndef CAS_H
#define CAS_H
#include "IComparable.h"

//Vytvoøte strukturu Cas, která obsahuje privátní položky int _hodiny(0 - 23), _minuty(0 - 59), _sekundy (0 - 59); 
class Cas : public IComparable { // Implementujte ve struktuøe rozhraní IComparable
private:
	int _hodiny;
	int _minuty;
	int _sekundy;
public:
	Cas(int _aHodiny, int _aMinuty, int _aSekundy); // Všechny atributy nastavte v konstruktoru.
	//(pøedpokládejte, že Cas se bude zase jen porovnávat s jiným objektem stejného typu, není nutná kontrola typu).
	virtual std::string toString() const override;
	virtual int compareTo(IComparable* obj) const override;
};

#endif // !CAS_H


