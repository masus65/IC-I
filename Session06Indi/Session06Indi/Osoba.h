//#pragma once
#ifndef OSOBA_H
#define OSOBA_H
#include <string>
#include "Adresa.h"
#include "Datum.h"

// Osoba(string _jmeno, string _prijmeni, Adresa _trvaleBydliste, Datum _datumNarozeni).
struct Osoba{
	std::string _jmeno;
	std::string _prijmeni;
	Adresa _trvaleBydliste;
	Datum _datumNarozeni;

	//Osoba(std::string _aJmeno, std::string _aPrijmeni, Adresa _aTrvaleBydliste, Datum _aDatumNarozeni);
	//Osoba();
	//~Osoba();

};

#endif // !OSOBA_H
