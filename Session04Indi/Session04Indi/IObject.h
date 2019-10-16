//#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H
#include <iostream>

using namespace std;

// Vytvoøte rozhraní (abstraktní tøídu) IObject, které obsahuje èistì virtuální metodu string toString() const,
class IObject {
private:

public:
	virtual ~IObject() {}
	virtual string toString() const = 0; // Vrací textovou reprezentaci objektu
};

#endif // !IOBJECT_H
