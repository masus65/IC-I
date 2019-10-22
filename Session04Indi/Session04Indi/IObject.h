//#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H
#include <iostream>
#include <string>

//using namespace std; //NEPOUZIVAT using v .H

// Vytvo�te rozhran� (abstraktn� t��du) IObject, kter� obsahuje �ist� virtu�ln� metodu string toString() const,
class IObject {
private:

public:
	virtual ~IObject() {}
	virtual std::string toString() const = 0; // Vrac� textovou reprezentaci objektu
};

#endif // !IOBJECT_H
