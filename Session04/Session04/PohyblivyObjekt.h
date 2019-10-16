//#pragma once
#ifndef POHYBLIVY_OBJEKT_H
#define POHYBLIVY_OBJEKT_H
#include "Objekt.h"

// Tøída PohyblivyObjekt : Potomek Objekt
class PohyblivyObjekt : public Objekt {
private:
	double uhelNatoceni; // Atribut : double uhelNatoceni(getter, setter; hodnota 0 – 2 * pi, 0 – sever, pi - jih)

public:
	double getUhelNatoceni() const; // getter

	void setUhelNatoceni(double aUhelNatoceni); // setter

};

#endif // !POHYBLIVY_OBJEKT_H

