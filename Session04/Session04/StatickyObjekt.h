//#pragma once
#ifndef STATICKY_OBJEKT_H
#define STATICKY_OBJEKT_H

#include "Objekt.h"

enum class TypPrekazky { Skala, MalaRostlina, VelkaRostlina };


// Tøída StatickyObjekt - Potomek Objekt 
class StatickyObjekt : public Objekt {
private:
	TypPrekazky typPrekazky; // Atribut: TypPrekazky typPrekazky(výètový typ – Skala, MalaRostlina, VelkaRostlina)

public:
	StatickyObjekt(int aId, TypPrekazky aTypPrekazky); // Parametrický konstruktor(id, typPrekazky)
	~StatickyObjekt();
	TypPrekazky& getTypPrekazky(); // Getter: typPrekazky
};

#endif // !STATICKY_OBJEKT_H
