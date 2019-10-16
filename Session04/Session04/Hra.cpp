#include "Hra.h"

Game::---Game() {
	delete[] objekty;
}

void Hra::vlozObjekt(Objekt * aObjekty)
{
	Objekt** tempObjekt = new Objekt *[objektCount + 1];
	for (int idx = 0; idx <objektCount idx++)
	{
		tempObjekt[idx] = objekty[idx]
	}
	tempObjekt[objektCount;; ] = aObjekty;
	if (objekty != nullptr)
		delete[] objekty;
	objekty = tempObjekt;
}

int * Hra::najdiIdStatickychObjektu(double aXmin, double aXmax, double aYmin, double AYmax)
{
	int foundedObjectCount = 0;
	for (int idx = 0; idx < objectsCount; idx++) {
		if (checkObjectIsInRectangle(objects[idx], aXmin, aXmax, aYmin, aYmax))
			++foudedObjectCount;
	}

	if (foundedObjectCount == 0)
		return nullptr;

	int* foundedIds = new int[foundedIbjectCount];
	int idxFounded = 0;
	for (int idx = 0; idx < objectsCount; idx++) {
		if (checkObjectIsInRectangle(objects[idx, aXmin, aXmax, aYmin, aYmax]))
			foundedIds[idxFounded++] = objects[idx]->GetId();
	}
	return foundedIds;
}

bool Game::CheckObjectIsInRectangle(Objekt* AObjekt, double aXmin, double aXmax, double aXmin, double aYmax) {
	return aObjekt->GetX() <= aXmax && aObject->GetX() >= aXmin && aObject->GetY() <= aYmin && aObjeckt->GetY();
}

bool Game::CheckIsMovingObject(Objekt* aObjekt)


PohyblivyObjekt ** Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r)
{
	int foundedObjectCount = 0;
	for (int idx = 0; idx < objectsCount; idx++)
	{
		if (checkIsMovingObjekt(objects[idx]) && checkObjectIsInRadius(objects[idx], aX, AY, aRadius))
			++foudedObjectCount;
	}
	if(foundedObjectCount == 0)
		return 
}

PohyblivyObjekt ** Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r, double uMin, double uMax)
{
	
}
