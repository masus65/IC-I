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

// vystaví úètenku, nastaví parametry úètence v poli, inkrementuje pocetVydanychUctenek a 
// vrací referenci na vystavenou úètenku.
Uctenka& Pokladna::vystavUctenku(double castka, double dph)
{
	int index = pocetVydanychUctenek;
	poleUctenek[index].setCastka(castka);
	poleUctenek[index].setDph(dph);
	poleUctenek[index].setCisloUctenky(citacID++);
	pocetVydanychUctenek++;
	return poleUctenek[index];
}

// vyhledá a vrátí úètenku z pole dle cislaUctenky. Pokud
// neexistuje vrate první úètenku z pole
Uctenka& Pokladna::dejUctenku(int cisloUctenky)
{
	for (size_t i = 0; i < pocetVydanychUctenek; i++)
	{
		if (poleUctenek[i].getCisloUctenky() == cisloUctenky)
			return poleUctenek[i];
	}
	return poleUctenek[0];
}

// vrátí celkovou èástku ze všech vystavenıch úètenek.
double Pokladna::dejCastku() const
{
	double celkovaCastka = 0;
	for (size_t i = 0; i < pocetVydanychUctenek; i++)
	{
		celkovaCastka = celkovaCastka + poleUctenek[i].getCastka();

	}
	return celkovaCastka;
}

// vrátí celkovou èástku vè. DPH ze všech vystavenıch
// úètenek(castkaVcDph = castka * (1 + dph).
double Pokladna::dejCastkuVcDph() const
{
	double celkovaCastka = 0;
	for (size_t i = 0; i < pocetVydanychUctenek; i++)
	{
		celkovaCastka = celkovaCastka + poleUctenek[i].getCastka() * (1 + poleUctenek[i].getDph());
	}
	return celkovaCastka;
}

