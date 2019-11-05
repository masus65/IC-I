//#pragma once
#ifndef OSOBA_H
#define OSOBA_H
#include <string>
#include "Adresa.h"
#include "Datum.h"
#include "Osoba.h"

// Osoba(string _jmeno, string _prijmeni, Adresa _trvaleBydliste, Datum _datumNarozeni).
class Osoba {
private:
	std::string _jmeno;
	std::string _prijmeni;
	Adresa _trvaleBydliste;
	Datum _datumNarozeni;

public:
	Osoba(std::string _aJmeno, std::string _aPrijmeni, Adresa _aTrvaleBydliste, Datum _aDatumNarozeni);
	Osoba();
	~Osoba();
	friend std::ostream& operator<<(std::ostream& os, const Osoba& p);
	friend std::istream& operator>>(std::istream& is, Osoba& p);
};

#endif // !OSOBA_H