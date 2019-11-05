#include "Adresa.h"

Adresa::Adresa(std::string aUlice, std::string aMesto, int aPsc)
{
	this->_ulice = aUlice;
	this->_mesto = aMesto;
	this->_psc = aPsc;
}

Adresa::Adresa()
{
}

std::ostream & operator<<(std::ostream & os, const Adresa & dt){
	os << dt._mesto<< " " << dt._ulice << " " << dt._psc;
	return os;
}

std::istream & operator>>(std::istream & is, Adresa & dt)
{
	is >> dt._mesto;
	is >> dt._ulice;
	is >> dt._psc;
	return is;
}
