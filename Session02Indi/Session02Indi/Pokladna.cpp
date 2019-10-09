#include <iostream>
#include "Pokladna.h"



int Pokladna::citacID = 1000;

Pokladna::Pokladna()
{
	pocetVydanychUctenek = 0;
	poleUctenek = new Uctenka[10];
}

Pokladna::~Pokladna()
{
	delete[] poleUctenek;
}

// vystav� ��tenku, nastav� parametry ��tence v poli, inkrementuje pocetVydanychUctenek a 
// vrac� referenci na vystavenou ��tenku.
Uctenka& Pokladna::vystavUctenku(double castka, double dph)
{
	int index = pocetVydanychUctenek;
	poleUctenek[index].setCastka(castka);
	poleUctenek[index].setDph(dph);
	poleUctenek[index].setCisloUctenky(citacID++);
	pocetVydanychUctenek++;
	return poleUctenek[index];
}

// vyhled� a vr�t� ��tenku z pole dle cislaUctenky. Pokud
// neexistuje vra�te prvn� ��tenku z pole
Uctenka& Pokladna::dejUctenku(int cisloUctenky)
{
	for (size_t i = 0; i < pocetVydanychUctenek; i++)
	{
		if (poleUctenek[i].getCisloUctenky() == cisloUctenky)
			return poleUctenek[i];
	}
	return poleUctenek[0];
}

// vr�t� celkovou ��stku ze v�ech vystaven�ch ��tenek.
double Pokladna::dejCastku() const
{
	double celkovaCastka = 0;
	for (size_t i = 0; i < pocetVydanychUctenek; i++)
	{
		celkovaCastka = celkovaCastka + poleUctenek[i].getCastka();

	}
	return celkovaCastka;
}

// vr�t� celkovou ��stku v�. DPH ze v�ech vystaven�ch
// ��tenek(castkaVcDph = castka * (1 + dph).
double Pokladna::dejCastkuVcDph() const
{
	double celkovaCastka = 0;
	for (size_t i = 0; i < pocetVydanychUctenek; i++)
	{
		celkovaCastka = celkovaCastka + poleUctenek[i].getCastka() * (1 + poleUctenek[i].getDph());
	}
	return celkovaCastka;
}

