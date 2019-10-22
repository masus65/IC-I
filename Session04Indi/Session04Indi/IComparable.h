//#pragma once
#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H
#include "IObject.h"

// Vytvoøte rozhraní IComparable(rozšiøuje rozhraní IObject), které obsahuje èistì virtuální metodu int compareTo(IComparable* obj) const.
class IComparable : public IObject {
private:

public:
	virtual ~IComparable() {};
	virtual int compareTo(IComparable* obj) const = 0;
	// V odvozených tøídách implementujte metodu následujícím
	// zpùsobem(left.compareTo(right)) :
	//	-levý objekt == pravý objekt – vrací 0
	//	- levý objekt < pravý objekt – vrací - 1
	//	- levý objekt > pravý objekt – vrací 1
	//string toString() const;
};

#endif // !ICOMPARABLE_H

