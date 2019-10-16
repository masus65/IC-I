#include "Hra.h"
#include "StatickyObjekt.h"
#include <typeinfo>
#define POCET_OBJEKTU 5

//Hra::Hra(int velikostPoleObjektu)
//{
//	this->velikostPoleObjektu = velikostPoleObjektu;
//	this->pocetObjektu = 0;
//	objekty = new Objekt *[velikostPoleObjektu];
//}

Hra::Hra()
{
	objekty = new Objekt*[POCET_OBJEKTU];
	this->pocetObjektu = 0;
}

void Hra::vlozObjekt(Objekt * o)
{
	objekty[pocetObjektu] = o;
}

int * Hra::najdiIdStatickychObjektu(double xMin, double xMax, double yMin, double yMax)
{
	int* poleId = new int[POCET_OBJEKTU];
	for (int i = 0; i < POCET_OBJEKTU; i++)
	{
		double oX = objekty[i]->GetX();
		double oY = objekty[i]->GetY();
		if (typeid(objekty[i]) == typeid(StatickyObjekt) && oX >= xMin && objekty && oY <= xMax && oY >= yMin && oY <= yMax) {}
	}
	return poleId;
}

PohyblivyObjekt ** Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r)
{
	return new PohyblivyObjekt*;
}

PohyblivyObjekt ** Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r, double uMin, double uMax)
{
	return new PohyblivyObjekt*;
}
