//#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H
#include <iostream>
#include <string>

//using namespace std; //NEPOUZIVAT using v .H

// Vytvoøte rozhraní (abstraktní tøídu) IObject, které obsahuje èistì virtuální metodu string toString() const,
class IObject {
private:

public:
	virtual ~IObject() {}
	virtual std::string toString() const = 0; // Vrací textovou reprezentaci objektu
};

#endif // !IOBJECT_H
