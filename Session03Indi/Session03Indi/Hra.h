//#pragma once
#ifndef HRA_H
#define HRA_H
//#include "Monstrum.h"
#include "PohyblivyObjekt.h"

// T��da Hra
class Hra {
private:
	Objekt** objekty; // Atribut : Objekt * * objekty -> Dynamicky alokovan� pole ukazatel� na Objekt

public:
	void vlozObjekt(Objekt* o); // Vlo�� objekt do pole.
	int* najdiIdStatickychObjektu(double xMin, double xMax, double yMin, double yMax); // Vr�t� pole id v�ech statick�ch objekt� v zadan�ch sou�adnic�ch.
	PohyblivyObjekt** najdiPohybliveObjektyVOblasti(double x, double y, double r); // Vr�t� pole ukazel� na pohybliv� objekty v kruhov� oblasti(S = [x, y], radius = r).
	PohyblivyObjekt** najdiPohybliveObjektyVOblasti(double x, double y, double r, double uMin, double uMax); // Viz p�edchoz�, nav�c kontrola �hlu nato�en�.

};

#endif // !HRA_H

