//#pragma once
#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H
#include "IObject.h"

// Vytvo�te rozhran� IComparable(roz�i�uje rozhran� IObject), kter� obsahuje �ist� virtu�ln� metodu int compareTo(IComparable* obj) const.
class IComparable : public IObject {
private:

public:
	virtual ~IComparable() {};
	virtual int compareTo(IComparable* obj) const = 0;
	// V odvozen�ch t��d�ch implementujte metodu n�sleduj�c�m
	// zp�sobem(left.compareTo(right)) :
	//	-lev� objekt == prav� objekt � vrac� 0
	//	- lev� objekt < prav� objekt � vrac� - 1
	//	- lev� objekt > prav� objekt � vrac� 1
	//string toString() const;
};

#endif // !ICOMPARABLE_H

