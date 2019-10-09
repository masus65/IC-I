#include <iostream>
#include "Pokladna.h"

#define POCET_UCTENEK 10
#define VYCHOZI_POCET_CITACE 1000
#include <stdexcept>


int Pokladna::citacID = VYCHOZI_POCET_CITACE;

Pokladna::Pokladna() : pocetVydanychUctenek(0)
{
	//pocetVydanychUctenek = 0; //narocnejsi
	poleUctenek = new Uctenka[POCET_UCTENEK];
}

//Pokladna::~Pokladna()
//{
//	delete[] poleUctenek;
//}

// vystaví úètenku, nastaví parametry úètence v poli, inkrementuje pocetVydanychUctenek a 
// vrací referenci na vystavenou úètenku.
Uctenka& Pokladna::vystavUctenku(double aCastka, double aDph)
{
	if (pocetVydanychUctenek == POCET_UCTENEK)
		throw std::overflow_error("Pokladna je plna. ");
	//int index = pocetVydanychUctenek;
	poleUctenek[pocetVydanychUctenek].SetCastka(aCastka);
	poleUctenek[pocetVydanychUctenek].SetDph(aDph);
	poleUctenek[pocetVydanychUctenek].SetCisloUctenky(citacID++);
	//pocetVydanychUctenek++;
	return poleUctenek[pocetVydanychUctenek++];
}

// vyhledá a vrátí úètenku z pole dle cislaUctenky. Pokud
// neexistuje vrate první úètenku z pole
Uctenka& Pokladna::dejUctenku(int cisloUctenky)
{
	for (int i = 0; i < pocetVydanychUctenek; i++)
	{
		if (poleUctenek[i].GetCisloUctenky() == cisloUctenky)
			return poleUctenek[i];
	}
	//return poleUctenek[0];
	throw std::invalid_argument("Uctenka nenalezena. ");
}

const Uctenka & Pokladna::dejCastku(int aCisloUctenky) const
{
	for (int i = 0; i < pocetVydanychUctenek; i++)
	{
		if (poleUctenek[i].GetCisloUctenky() == aCisloUctenky)
			return poleUctenek[i];
	}
	throw std::invalid_argument("Uctenka nenalezena. ");
}

// vrátí celkovou èástku ze všech vystavenıch úètenek.
double Pokladna::dejCastku() const
{
	double celkovaCastka = 0.0;
	for (int i = 0; i < pocetVydanychUctenek; i++)
	{
		celkovaCastka = celkovaCastka + poleUctenek[i].GetCastka();

	}
	return celkovaCastka;
}

// vrátí celkovou èástku vè. DPH ze všech vystavenıch
// úètenek(castkaVcDph = castka * (1 + dph).
double Pokladna::dejCastkuVcDph() const
{
	double celkovaCastka = 0.0;
	for (int i = 0; i < pocetVydanychUctenek; i++)
	{
		//celkovaCastka = celkovaCastka + poleUctenek[i].GetCastka() * (1 + poleUctenek[i].GetDph());
		celkovaCastka += poleUctenek[i].GetDph();
	}
	return celkovaCastka;
}

