#pragma once
//#pragma once
//Vytvo�te t��du Pokladna, kter� obsahuje dynamicky alokovan� pole ��tenek o 10 prvc�ch a
//atribut pocetVydanychUctenek, kter� p�edstavuje po�et vydan�ch ��tenek.D�le ve t��d�
//vytvo�te priv�tn� statick� atribut citacId, kter� slou�� pro generov�n� ��sel ��tenek.Na
//za��tku inicializujte statick� atribut na hodnotu 1000. Ve t��d� Pokladna vytvo�te ve�ejn�
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
	Uctenka& vystavUctenku(double aCastka, double aDph); // vystav� ��tenku, nastav� parametry ��tence v poli, inkrementuje pocetVydanychUctenek a vrac� referenci na vystavenou ��tenku.
	Uctenka& dejUctenku(int aCisloUctenky); // vyhled� a vr�t� ��tenku z pole dle cislaUctenky.Pokud neexistuje vra�te prvn� ��tenku z pole.
	const Uctenka& Pokladna::dejCastku(int aCisloUctenky) const;
	double dejCastku() const; // vr�t� celkovou ��stku ze v�ech vystaven�ch ��tenek.
	double dejCastkuVcDph() const; // vr�t� celkovou ��stku v�.DPH ze v�ech vystaven�ch ��tenek(castkaVcDph = castka * (1 + dph).

};



#endif // !POKLADNA_H