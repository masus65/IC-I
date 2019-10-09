#pragma once
//#pragma once
//Vytvoøte tøídu Pokladna, která obsahuje dynamicky alokované pole úètenek o 10 prvcích a
//atribut pocetVydanychUctenek, kterı pøedstavuje poèet vydanıch úètenek.Dále ve tøídì
//vytvoøte privátní statickı atribut citacId, kterı slouí pro generování èísel úètenek.Na
//zaèátku inicializujte statickı atribut na hodnotu 1000. Ve tøídì Pokladna vytvoøte veøejné
//metody


#ifndef POKLADNA_H
#define POKLADNA_H
#include <string>
#include "Uctenka.h"


class Pokladna {
private:
	Uctenka* poleUctenek;
	int pocetVydanychUctenek;
	static int citacID;
public:
	Pokladna();
	~Pokladna() { delete[] poleUctenek };
	Uctenka& vystavUctenku(double aCastka, double aDph); // vystaví úètenku, nastaví parametry úètence v poli, inkrementuje pocetVydanychUctenek a vrací referenci na vystavenou úètenku.
	Uctenka& dejUctenku(int aCisloUctenky); // vyhledá a vrátí úètenku z pole dle cislaUctenky.Pokud neexistuje vrate první úètenku z pole.
	const Uctenka& Pokladna::dejCastku(int aCisloUctenky) const;
	double dejCastku() const; // vrátí celkovou èástku ze všech vystavenıch úètenek.
	double dejCastkuVcDph() const; // vrátí celkovou èástku vè.DPH ze všech vystavenıch úètenek(castkaVcDph = castka * (1 + dph).

};



#endif // !POKLADNA_H