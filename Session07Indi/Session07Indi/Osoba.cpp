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

void Osoba::read(std::ifstream* in)
{
	
	in->read((char*)_jmeno, _jmeno.size() + 1);
	in->read((char*)_prijmeni, _prijmeni.size() + 1);
	in->read((char*)_trvaleBydliste.getUlice(), _trvaleBydliste.getUlice().size() + 1);
	in->read((char*)_residence.getZip(), _residence.getZip().size() + 1);
	in->read((char*)_residence.getCity(), _residence.getCity().size() + 1);
	in->read((char*)_birthDate.getDay(), sizeof(int));
	in->read((char*)_birthDate.getMonth(), sizeof(int));
	in->read((char*)_birthDate.getYear(), sizeof(int));
}

void Osoba::write(std::ofstream* out)
{
	std::string jmeno = _jmeno;
	std::string prijmeni = _prijmeni;
	std::string trvaleBydliste = trvaleBydliste.getStreet();
	std::string city = _residence.getCity();
	std::string zip = _residence.getZip();
	int day = _birthDate.getDay();
	int month = _birthDate.getMonth();
	int year = _birthDate.getYear();

	out->write((char*)&name, name.size() + 1);
	out->write((char*)&last_name, last_name.size() + 1);
	out->write((char*)&street, street.size() + 1);
	out->write((char*)&zip, zip.size() + 1);
	out->write((char*)&city, city.size() + 1);
	out->write((char*)&day, sizeof(int));
	out->write((char*)&month, sizeof(int));
	out->write((char*)&year, sizeof(int));
}