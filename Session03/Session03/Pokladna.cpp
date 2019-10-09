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

// vystav� ��tenku, nastav� parametry ��tence v poli, inkrementuje pocetVydanychUctenek a 
// vrac� referenci na vystavenou ��tenku.
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

// vyhled� a vr�t� ��tenku z pole dle cislaUctenky. Pokud
// neexistuje vra�te prvn� ��tenku z pole
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

// vr�t� celkovou ��stku ze v�ech vystaven�ch ��tenek.
double Pokladna::dejCastku() const
{
	double celkovaCastka = 0.0;
	for (int i = 0; i < pocetVydanychUctenek; i++)
	{
		celkovaCastka = celkovaCastka + poleUctenek[i].GetCastka();

	}
	return celkovaCastka;
}

// vr�t� celkovou ��stku v�. DPH ze v�ech vystaven�ch
// ��tenek(castkaVcDph = castka * (1 + dph).
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

