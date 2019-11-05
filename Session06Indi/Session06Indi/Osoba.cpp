#include "Osoba.h"

Osoba::Osoba(std::string _aJmeno, std::string _aPrijmeni, Adresa _aTrvaleBydliste, Datum _aDatumNarozeni)
{
	this->_jmeno = _aJmeno;
	this->_prijmeni = _aPrijmeni;
	this->_datumNarozeni = _aDatumNarozeni;
	this->_trvaleBydliste = _aTrvaleBydliste;
}

Osoba::Osoba()
{
}

Osoba::~Osoba()
{
}

std::ostream & operator<<(std::ostream & os, const Osoba & p)
{
	os << p._jmeno << " " << p._prijmeni << std::endl << p._datumNarozeni << std::endl << p._trvaleBydliste << std::endl;
	return os;
}

std::istream & operator>>(std::istream & is, Osoba & p)
{
	is >> p._jmeno;
	is >> p._prijmeni;
	is >> p._datumNarozeni;
	is >> p._trvaleBydliste;
	return is;
}
