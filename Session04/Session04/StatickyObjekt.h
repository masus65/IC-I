//#pragma once
#ifndef STATICKY_OBJEKT_H
#define STATICKY_OBJEKT_H

#include "Objekt.h"

enum class TypPrekazky { Skala, MalaRostlina, VelkaRostlina };


// T��da StatickyObjekt - Potomek Objekt 
class StatickyObjekt : public Objekt {
private:
	TypPrekazky typPrekazky; // Atribut: TypPrekazky typPrekazky(v��tov� typ � Skala, MalaRostlina, VelkaRostlina)

public:
	StatickyObjekt(int aId, TypPrekazky aTypPrekazky); // Parametrick� konstruktor(id, typPrekazky)
	~StatickyObjekt();
	TypPrekazky& getTypPrekazky(); // Getter: typPrekazky
};

#endif // !STATICKY_OBJEKT_H
