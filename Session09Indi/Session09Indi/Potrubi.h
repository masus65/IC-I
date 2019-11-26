//#pragma once
#ifndef POTRUBI_H
#define POTRUBI_H
#include "APotrubniPrvek.h"

#include <iostream>



class Potrubi : IPotrubi {
private:
	APotrubniPrvek** prvky;
	int rozmer;

public:
	Potrubi(std::istream& is);
	virtual ~Potrubi();

	virtual const APotrubniPrvek* DejPrvek(int x, int y) const override;
	virtual bool JePotrubiOk() const override;
};



#endif // !POTRUBI_H

