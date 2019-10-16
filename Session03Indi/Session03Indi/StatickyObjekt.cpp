#include "StatickyObjekt.h"

StatickyObjekt::StatickyObjekt(int aId, TypPrekazky aTypPrekazky) : Objekt(aId)
{
	Objekt* objekt = new Objekt(aId);
	this->typPrekazky = aTypPrekazky;
}

StatickyObjekt::~StatickyObjekt()
{
}

TypPrekazky & StatickyObjekt::getTypPrekazky()
{
	this->typPrekazky;
}
