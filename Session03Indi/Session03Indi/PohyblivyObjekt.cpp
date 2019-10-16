#include "PohyblivyObjekt.h"

//double PohyblivyObjekt::getUhelNatoceni() const
//{
//	return this->uhelNatoceni;
//}
//
//void PohyblivyObjekt::setUhelNatoceni(double aUhelNatoceni)
//{
//	this->uhelNatoceni = aUhelNatoceni;
//}

PohyblivyObjekt::~PohyblivyObjekt()
{
}

PohyblivyObjekt::PohyblivyObjekt(int aId, double aUhelNatoceni) :Objekt(aId) {
	setUhelNatoceni(aUhelNatoceni);
}

double PohyblivyObjekt::getUhelNatoceni() {
	return uhelNatoceni;
}

void PohyblivyObjekt::setUhelNatoceni(double aUhelNatoceni) {
	if (aUhelNatoceni > 2 * M_PI || aUhelNatoceni < 0) {
		throw std::out_of_range("Uhel mimo rozsah");
	}
	uhelNatoceni = aUhelNatoceni;
}
