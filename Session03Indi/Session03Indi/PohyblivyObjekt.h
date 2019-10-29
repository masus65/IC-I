//#pragma once
#ifndef POHYBLIVY_OBJEKT_H
#define POHYBLIVY_OBJEKT_H
#include "Objekt.h"

// Tøída PohyblivyObjekt : Potomek Objekt
class PohyblivyObjekt : public Objekt {
private:
	double uhelNatoceni; // Atribut : double uhelNatoceni(getter, setter; hodnota 0 – 2 * pi, 0 – sever, pi - jih)

public:
	PohyblivyObjekt();
	void setUhelNatoceni(double aUhelNatoceni); // setter
	double getUhelNatoceni() const; // getter

};

#endif // !POHYBLIVY_OBJEKT_H

