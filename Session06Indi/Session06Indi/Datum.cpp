#include "Datum.h"

Datum::Datum(int aDen, int aMesic, int aRok){
	this->_dne = aDen;
	this->_mesic = aMesic;
	this->_rok = aRok;
}

Datum::Datum(){
}

Datum::~Datum(){
}

std::ostream & operator<<(std::ostream & os, const Datum & d){
	os << d._dne << " " << d._mesic << " " << d._rok;
	return os;
}

std::istream & operator>>(std::istream & is, Datum & d){
	is >> d._dne;
	is >> d._mesic;
	is >> d._rok;
	return is;
	
}