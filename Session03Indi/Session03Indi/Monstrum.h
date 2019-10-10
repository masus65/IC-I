//#pragma once
#ifndef MONSTRUM_H
#define MONSTRUM_H
#include "PohyblivyObjekt.h"

// Tøída Monstrum - Potomek PohyblivyObjekt
class Monsturm : public PohyblivyObjekt {
private:
	int hp; // Atribut : int hp(getter, setter)
	int maxhp;// Atribut : int maxhp(getter, setter)

public:
	int getHp() const;
	int getMaxHp() const;

	void setHp(int aHp);
	void setMaxHp(int aMaxHp);
};

#endif // !MONSTRUM_H

