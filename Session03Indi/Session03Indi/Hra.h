//#pragma once
#ifndef HRA_H
#define HRA_H
//#include "Monstrum.h"
#include "PohyblivyObjekt.h"

// Tøída Hra
class Hra {
private:
	Objekt** objekty; // Atribut : Objekt * * objekty -> Dynamicky alokované pole ukazatelù na Objekt

public:
	void vlozObjekt(Objekt* o); // Vloží objekt do pole.
	int* najdiIdStatickychObjektu(double xMin, double xMax, double yMin, double yMax); // Vrátí pole id všech statických objektù v zadaných souøadnicích.
	PohyblivyObjekt** najdiPohybliveObjektyVOblasti(double x, double y, double r); // Vrátí pole ukazelù na pohyblivé objekty v kruhové oblasti(S = [x, y], radius = r).
	PohyblivyObjekt** najdiPohybliveObjektyVOblasti(double x, double y, double r, double uMin, double uMax); // Viz pøedchozí, navíc kontrola úhlu natoèení.

};

#endif // !HRA_H

