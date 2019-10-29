#include "Osoba.h"

Entity::Osoba::Osoba() : jmeno(""), telefon(""), id(0)
{
}

Entity::Osoba::Osoba(std::string jmeno, std::string telefon, int id) : jmeno(jmeno), telefon(telefon), id(id){
//	this->jmeno = jmeno;
//	this->telefon = telefon;
//	this->id = id;
}

int Entity::Osoba::getId() const{
	return id;
}

std::string Entity::Osoba::getJmeno() const{
	return jmeno;
}

std::string Entity::Osoba::getTelefon() const{
	return telefon;
}

Entity::Osoba::~Osoba() {

}