#include "StatickyObjekt.h"



StatickyObjekt::StatickyObjekt(int aId, TypPrekazky aTypPrekazky) :Objekt(aId) {
	this->id = aId;
	this->typPrekazky = aTypPrekazky;
}
TypPrekazky StatickyObjekt::getTypPrekazky(){
	return typPrekazky;
}